//  File     : /adm/daemons/lint_d.c
//  Purpose  : 全站 LPC 編譯掃描器。
//
//  FluffOS 的編譯是 lazy 的 —— 一個檔案要等到有人真的用到它才會被編譯，
//  所以升級驅動之後，語法或型別上不再合法的檔案可能潛伏很久才爆出來。
//  這個 daemon 把整棵樹逐一 load_object() 一遍，把編譯期錯誤收集到 /log/lint。
//
//  用法（巫師）：
//      eval return "/adm/daemons/lint_d"->scan("/std");
//      eval return "/adm/daemons/lint_d"->status();
//
//  注意：載入物件是有副作用的（daemon 會啟動、房間會 clone 出裡面的 NPC），
//  所以請在測試環境跑，不要對正式站整棵樹掃。
//
//  06-09-10 升級為 FluffOS v2026 驅動時新增

#include <mudlib.h>

#define BATCH  20
#define LOGF   "lint"

nosave string *queue;
nosave int idx, nerr, nok, running;

void collect(string dir);
void step();

void create() { seteuid(getuid()); }

int scan(string root)
{
	if( running ) return -1;
	queue = ({});
	idx = 0; nerr = 0; nok = 0;
	collect(root);
	running = 1;
	log_file(LOGF, "==== lint " + root + " : " + sizeof(queue) +
		" files @ " + ctime(time()) + " ====\n");
	call_out("step", 1);
	return sizeof(queue);
}

void collect(string dir)
{
	mixed *fs;
	string nm;
	int i, l;

	if( dir == "" || dir[strlen(dir)-1] != '/' ) dir += "/";
	fs = get_dir(dir, -1);
	if( !fs ) return;
	for( i = 0; i < sizeof(fs); i++ ) {
		nm = fs[i][0];
		if( nm == "." || nm == ".." ) continue;
		if( fs[i][1] == -2 ) { collect(dir + nm); continue; }
		l = strlen(nm);
		if( l > 2 && nm[l-2..l-1] == ".c" )
			queue += ({ dir + nm[0..l-3] });
	}
}

void step()
{
	mixed err;
	int n;

	for( n = 0; idx < sizeof(queue) && n < BATCH; idx++, n++ ) {
		err = catch( load_object(queue[idx]) );
		if( err ) {
			nerr++;
			log_file(LOGF, queue[idx] + "\n    " + err);
		} else nok++;
	}
	if( idx < sizeof(queue) ) { call_out("step", 1); return; }
	running = 0;
	log_file(LOGF, "==== done: " + nok + " ok, " + nerr + " failed ====\n");
}

string status()
{
	return sprintf("%d/%d  ok=%d  err=%d  %s\n",
		idx, queue ? sizeof(queue) : 0, nok, nerr,
		running ? "running" : "idle");
}
