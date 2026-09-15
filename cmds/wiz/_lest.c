//  File     : /cmds/wiz/_lest.c
//  Purpose  : 在遊戲裡跑 lest（LPC 測試執行器）。
//  06-09-11 建立

#include <mudlib.h>
#include <lest.h>

inherit DAEMON;

int help();

int cmd_lest(string arg)
{
	int n, keep;
	string *un;

	if( !arg || arg == "" ) {
		write( (string)LEST_D->report() );
		return 1;
	}

	if( arg == "-u" || arg == "uncovered" ) {
		un = (string *)LEST_D->uncovered();
		if( !sizeof(un) ) { write("上次掃描的檔案都有 spec 了，或還沒跑過。\n"); return 1; }
		write(sprintf("還沒有 spec 的檔案（%d 個，列出前 40 個）：\n  %s\n",
			sizeof(un), implode(un[0..(sizeof(un) > 40 ? 39 : sizeof(un)-1)], "\n  ")));
		return 1;
	}

	//  預設會把記憶體裡已經載入的舊版本砍掉重編，-k 則沿用。
	if( sscanf(arg, "-k %s", arg) == 1 || sscanf(arg, "--keep %s", arg) == 1 )
		keep = 1;

	arg = resolv_path((string)this_player()->query("cwd"), arg);
	n = (int)LEST_D->run(arg, keep);
	if( n == -1 ) { write("lest 正在跑，請等它跑完。\n"); return 1; }
	if( n == -2 ) { write("路徑不對。\n"); return 1; }
	write(sprintf("開始測試 %s：%d 個檔案%s。跑完用 lest 看報告。\n",
		arg, n, keep ? "（沿用已載入的版本）" : "（會強制重編）"));
	return 1;
}

int help()
{
	write( @TEXT
指令：lest <目錄>       對目錄底下所有 .c 跑測試
      lest -k <目錄>    同上，但沿用記憶體裡已經載入的版本
      lest              顯示上次的報告
      lest -u           列出還沒有 spec 的檔案

lest 預設會先把要測的檔案（含它的 spec）從記憶體裡砍掉再 load，
確保測到的是磁碟上最新的程式 —— 否則改完直接 lest，測到的會是改之前
那一份，而且不會有任何跡象。身上有玩家的物件、master 與 PROTECT_FILES
不會被砍。不想動到已載入的物件時用 -k。

lest 分兩層檢查：

  第一層：每個 .c 都 load 一遍，抓編譯期錯誤。FluffOS 是 lazy 編譯，
          檔案沒被用到就不會編譯，壞掉的檔案可以潛伏很久。

  第二層：xxx.c 旁邊若有 xxx.spec.c，就把裡面每個 test_ 開頭的函式跑一遍。

寫一個 spec 檔（例如 /obj/bandage.spec.c 測 /obj/bandage.c）：

    #include <lest.h>
    inherit SPEC;

    void test_c_name(object ob) { expect_eq(ob->query("c_name"), "繃帶", "中文名"); }
    void test_weight(object ob) { expect_gt(ob->query("weight"), 0, "重量為正"); }

（LPC 識別字只能用 ASCII，函式名請用英文，中文寫在描述裡。）

可用的斷言：expect_eq、expect_ne、expect_gt、expect_true、
            expect_object、expect_string、expect（自己給條件）。

受測物件預設是 clone 出來的。房間或 daemon 這種不該 clone 的，
在 spec 裡覆寫 lest_subject(string target) 自己決定怎麼取得。

注意 load 物件是有副作用的（daemon 會啟動、房間會 clone 出 NPC），
請在測試環境跑。
TEXT
	);
	return 1;
}
