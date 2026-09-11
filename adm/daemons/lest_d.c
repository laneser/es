//  File     : /adm/daemons/lest_d.c
//  Purpose  : lest —— MUD 裡的 LPC 測試執行器（lint_d 的超集）。
//
//  兩層檢查：
//    第一層（所有 .c 都做）：load_object() 一遍，抓編譯期錯誤。
//        FluffOS 是 lazy 編譯，檔案沒被用到就不會編譯，壞掉的檔案可以潛伏很久。
//    第二層（只有寫了 spec 的做）：xxx.c 旁邊若有 xxx.spec.c，
//        就 clone 它、把每個 test_ 開頭的函式跑一遍、收集斷言結果，最後清掉。
//
//  用法（巫師）：
//      lest /obj              掃一個目錄
//      lest                   接續看上次的報告
//  或直接呼叫：
//      "/adm/daemons/lest_d"->run("/obj");
//      "/adm/daemons/lest_d"->report();
//
//  注意：load_object() 是有副作用的（daemon 會啟動、房間會 clone 出 NPC），
//  請在測試環境跑，不要對正式站整棵樹掃。
//
//  06-09-11 建立，取代原本只做第一層的 lint_d

#include <lest.h>

#define BATCH   20
#define LOGF    "lest"

nosave string *queue;
nosave int idx, running;
nosave int n_load_ok, n_load_err, n_spec_files, n_pass, n_fail;
nosave string *fail_lines;
nosave string scan_root;

void collect(string dir);
void step();
int run_spec(string target, string spec_file);

void create() { seteuid(getuid()); }

int run(string root)
{
	if( running ) return -1;
	if( !root || root == "" ) return -2;
	queue = ({});
	idx = 0;
	n_load_ok = 0; n_load_err = 0; n_spec_files = 0; n_pass = 0; n_fail = 0;
	fail_lines = ({});
	scan_root = root;
	collect(root);
	running = 1;
	log_file(LOGF, sprintf("\n==== lest %s : %d files @ %s ====\n",
		root, sizeof(queue), ctime(time())));
	call_out("step", 1);
	return sizeof(queue);
}

//  收集目錄下所有 .c，但跳過 *.spec.c —— 那些是測試檔本身，不是受測對象
void collect(string dir)
{
	mixed *fs;
	string nm, base;
	int i, l;

	if( dir == "" || dir[strlen(dir)-1] != '/' ) dir += "/";
	fs = get_dir(dir, -1);
	if( !fs ) return;
	for( i = 0; i < sizeof(fs); i++ ) {
		nm = fs[i][0];
		if( nm == "." || nm == ".." ) continue;
		if( fs[i][1] == -2 ) { collect(dir + nm); continue; }
		l = strlen(nm);
		if( l <= 2 || nm[l-2..l-1] != ".c" ) continue;
		base = nm[0..l-3];
		l = strlen(base);
		//  跳過測試檔自己
		if( l > 5 && base[l-5..l-1] == SPEC_SUFFIX ) continue;
		queue += ({ dir + base });
	}
}

void step()
{
	mixed err;
	string target, spec_file;
	int n;

	for( n = 0; idx < sizeof(queue) && n < BATCH; idx++, n++ ) {
		target = queue[idx];

		//  第一層：載入
		err = catch( load_object(target) );
		if( err ) {
			n_load_err++;
			fail_lines += ({ sprintf("[載入] %s\n    %s", target, err) });
			log_file(LOGF, sprintf("[載入失敗] %s\n    %s", target, err));
			continue;
		}
		n_load_ok++;

		//  第二層：有 spec 才跑
		spec_file = target + SPEC_SUFFIX;
		if( file_size(spec_file + ".c") > 0 ) {
			n_spec_files++;
			run_spec(target, spec_file);
		}
	}
	if( idx < sizeof(queue) ) { call_out("step", 1); return; }
	running = 0;
	log_file(LOGF, sprintf("==== done: %d loaded, %d load-failed, %d spec files, %d pass, %d fail ====\n",
		n_load_ok, n_load_err, n_spec_files, n_pass, n_fail));
}

//  跑一個 spec：clone 測試物件 → 取得受測對象 → 逐一執行 test_* → 收集 → 清理
int run_spec(string target, string spec_file)
{
	object spec, subject;
	string *fns, fn;
	mixed *res;
	mixed err;
	int i;

	err = catch( spec = clone_object(spec_file) );
	if( err || !spec ) {
		n_fail++;
		fail_lines += ({ sprintf("[spec 載入] %s\n    %s", spec_file, err ? err : "clone 失敗\n") });
		return 0;
	}

	spec->lest_reset();

	err = catch( subject = spec->lest_subject(target) );
	if( err ) {
		n_fail++;
		fail_lines += ({ sprintf("[spec 建立受測物件] %s\n    %s", spec_file, err) });
		destruct(spec);
		return 0;
	}

	fns = functions(spec);
	for( i = 0; i < sizeof(fns); i++ ) {
		fn = fns[i];
		if( strlen(fn) < 6 || fn[0..4] != "test_" ) continue;
		err = catch( call_other(spec, fn, subject) );
		if( err ) {
			n_fail++;
			fail_lines += ({ sprintf("[%s] %s 拋出錯誤\n    %s", spec_file, fn, err) });
		}
	}

	res = spec->lest_results();
	for( i = 0; i < sizeof(res); i++ ) {
		if( res[i][0] ) { n_pass++; continue; }
		n_fail++;
		fail_lines += ({ sprintf("[%s] %s\n    %s", spec_file, res[i][1], res[i][2]) });
		log_file(LOGF, sprintf("[斷言失敗] %s : %s\n    %s\n",
			spec_file, res[i][1], res[i][2]));
	}

	catch( spec->lest_cleanup(subject) );
	if( spec ) destruct(spec);
	return 1;
}

string status()
{
	return sprintf("%d/%d  %s\n", idx, queue ? sizeof(queue) : 0,
		running ? "running" : "idle");
}

//  完整報告
string report()
{
	string out;
	int total, i, cover;

	if( !queue ) return "還沒跑過。用法： lest <目錄>\n";
	total = sizeof(queue);
	cover = total ? n_spec_files * 1000 / total : 0;

	out = sprintf("\n===== lest 報告：%s =====\n", scan_root);
	out += sprintf("受測檔案      : %d\n", total);
	out += sprintf("  載入成功    : %d\n", n_load_ok);
	out += sprintf("  載入失敗    : %d\n", n_load_err);
	out += sprintf("有 spec 的檔案: %d  (覆蓋率 %d.%d%%)\n",
		n_spec_files, cover / 10, cover % 10);
	out += sprintf("  斷言通過    : %d\n", n_pass);
	out += sprintf("  斷言失敗    : %d\n", n_fail);

	if( sizeof(fail_lines) ) {
		out += "\n--- 失敗明細（最多 20 筆）---\n";
		for( i = 0; i < sizeof(fail_lines) && i < 20; i++ )
			out += fail_lines[i] + "\n";
		if( sizeof(fail_lines) > 20 )
			out += sprintf("...另有 %d 筆，詳見 /log/%s\n",
				sizeof(fail_lines) - 20, LOGF);
	}
	out += sprintf("\n完整記錄： /log/%s\n", LOGF);
	return out;
}

//  只列出還沒有 spec 的檔案，方便知道下一個該補哪裡
string *uncovered()
{
	string *out;
	int i;

	if( !queue ) return ({});
	out = ({});
	for( i = 0; i < sizeof(queue); i++ )
		if( file_size(queue[i] + SPEC_SUFFIX + ".c") <= 0 )
			out += ({ queue[i] });
	return out;
}
