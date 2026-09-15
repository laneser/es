//  File     : /adm/daemons/snapshotd.spec.c
//  /adm/daemons/snapshotd.c 的 spec。
//
//  這支 daemon 難的地方全在 d1/d7/d30 的推格規則：算錯不會報錯，只會在
//  一個月後才發現「一個月前那份」其實是昨天的。所以 plan_cascade() 與
//  plan_trim() 都寫成不碰檔案的純函式，這裡直接餵檔名清單驗證。

#include <lest.h>
#include <daemons.h>

inherit SPEC;

#define DAY	(24 * 60 * 60)
#define NOW	1789000000

//  受測的是 daemon 本體，不是可以 clone 的物件。
object lest_subject(string target)
{
	return load_object(SNAPSHOT_D);
}

//  ------------------------------------------------------------------
//  parse_name()
//  ------------------------------------------------------------------

void test_parse_ring_name(object ob)
{
	mixed *got;

	got = ob->parse_name("1789000000.o");
	expect_eq(got[0], "", "近期環的標籤是空字串");
	expect_eq(got[1], 1789000000, "時戳要拆得出來");
}

void test_parse_tier_name(object ob)
{
	mixed *got;

	got = ob->parse_name("d30-1789000000.o");
	expect_eq(got[0], "d30", "長期那三格要拆出標籤");
	expect_eq(got[1], 1789000000, "長期那三格也要拆出時戳");
}

void test_parse_rejects_non_snapshot(object ob)
{
	expect_eq(ob->parse_name("README"), 0, "沒有 .o 的不算快照");
	expect_eq(ob->parse_name(".o"), 0, "只有副檔名的不算快照");
	expect_eq(ob->parse_name(0), 0, "不是字串時要回 0，不要爆掉");
}

//  ------------------------------------------------------------------
//  plan_trim() —— 近期環的汰換
//  ------------------------------------------------------------------

//  產生 n 個間隔一小時的近期環檔名，最舊的排在前面。
string *ring(int n)
{
	string *out;
	int i;

	out = ({ });
	for( i = 0; i < n; i++ )
		out += ({ sprintf("%d.o", NOW - (n - i) * 3600) });
	return out;
}

void test_trim_keeps_everything_when_under_limit(object ob)
{
	expect_eq(sizeof(ob->plan_trim(ring(ob->query_keep()))), 0,
		"剛好等於保留上限時不該刪東西");
}

void test_trim_drops_the_oldest(object ob)
{
	string *files, *doomed;

	files = ring(ob->query_keep() + 3);
	doomed = ob->plan_trim(files);
	expect_eq(sizeof(doomed), 3, "超出三份就刪三份");
	expect_eq(doomed[0], files[0], "要從最舊的開始刪");
	expect_eq(doomed[2], files[2], "刪的是連續最舊的那幾份");
}

void test_trim_never_touches_tiers(object ob)
{
	string *files, *doomed;
	int i;

	files = ring(ob->query_keep() + 5) +
		({ "d1-1788000000.o", "d7-1787000000.o", "d30-1786000000.o" });
	doomed = ob->plan_trim(files);
	expect_eq(sizeof(doomed), 5, "長期三格不該算進近期環的份數");
	for( i = 0; i < sizeof(doomed); i++ )
		expect_true(doomed[i][0..0] != "d",
			"長期三格永遠不該被近期環的汰換刪掉");
}

void test_trim_survives_empty_dir(object ob)
{
	expect_eq(sizeof(ob->plan_trim(({ }))), 0, "空目錄不該有動作");
	expect_eq(sizeof(ob->plan_trim(0)), 0, "傳 0 進來也不該爆掉");
}

//  ------------------------------------------------------------------
//  plan_cascade() —— 長期三格的推格
//  ------------------------------------------------------------------

//  找出計畫裡對某一格的動作，回傳 ({ 動作, 來源, 目的 })，沒有就回傳 0。
mixed *op_for(mixed *ops, string tag)
{
	string want;
	int i;

	want = tag + "-";
	for( i = 0; i < sizeof(ops); i++ )
		if( stringp(ops[i][2]) &&
			ops[i][2][0..strlen(want)-1] == want ) return ops[i];
	return 0;
}

void test_first_snapshot_fills_d1_only(object ob)
{
	mixed *ops;

	ops = ob->plan_cascade(({ "1789000000.o" }), "1789000000.o", NOW);
	expect_eq(sizeof(ops), 1, "第一次快照只該產生一個動作");
	expect_eq(ops[0][0], "copy", "近期環那份要留著，所以是複製不是搬移");
	expect_eq(ops[0][2], "d1-1789000000.o", "第一份要落在 d1");
}

void test_fresh_d1_is_left_alone(object ob)
{
	mixed *ops;

	//  d1 才一小時大，整串都不該動。
	ops = ob->plan_cascade(
		({ "1789000000.o", sprintf("d1-%d.o", NOW - 3600) }),
		"1789000000.o", NOW);
	expect_eq(sizeof(ops), 0, "d1 還不到一天就不該有任何動作");
}

void test_day_old_d1_moves_into_empty_d7(object ob)
{
	mixed *ops, *op;

	ops = ob->plan_cascade(
		({ "1789000000.o", sprintf("d1-%d.o", NOW - DAY) }),
		"1789000000.o", NOW);

	op = op_for(ops, "d7");
	expect_true(op != 0, "滿一天的 d1 要推進空著的 d7");
	expect_eq(op[0], "rename", "往下推是搬移，不是複製");
	expect_eq(op[1], sprintf("d1-%d.o", NOW - DAY), "搬的是舊的那份 d1");

	op = op_for(ops, "d1");
	expect_eq(op[0], "copy", "d1 由最新的快照補上");
	expect_eq(op[2], "d1-1789000000.o", "補上的是這次的時戳");
}

void test_old_d1_is_dropped_when_d7_not_due(object ob)
{
	mixed *ops, *op;

	//  d1 滿一天了，但 d7 才兩天大（不到七天），舊的 d1 直接丟掉。
	ops = ob->plan_cascade(
		({ "1789000000.o", sprintf("d1-%d.o", NOW - DAY),
			sprintf("d7-%d.o", NOW - 2 * DAY) }),
		"1789000000.o", NOW);

	expect_eq(op_for(ops, "d7"), 0, "d7 還沒滿一週就不該被換掉");
	expect_eq(ops[0][0], "rm", "舊的 d1 要被刪掉");
	expect_eq(ops[0][1], sprintf("d1-%d.o", NOW - DAY), "刪的是舊的那份 d1");
	expect_eq(op_for(ops, "d1")[0], "copy", "d1 仍然要換成最新的");
}

void test_full_chain_promotes_every_tier(object ob)
{
	mixed *ops, *op;

	//  d1 滿一天、d7 滿一週、d30 還空著 —— 三格一起往下推。
	ops = ob->plan_cascade(
		({ "1789000000.o", sprintf("d1-%d.o", NOW - DAY),
			sprintf("d7-%d.o", NOW - 8 * DAY) }),
		"1789000000.o", NOW);

	op = op_for(ops, "d30");
	expect_true(op != 0, "滿一週的 d7 要推進空著的 d30");
	expect_eq(op[1], sprintf("d7-%d.o", NOW - 8 * DAY), "d30 收的是舊的 d7");

	op = op_for(ops, "d7");
	expect_eq(op[1], sprintf("d1-%d.o", NOW - DAY), "d7 收的是舊的 d1");

	op = op_for(ops, "d1");
	expect_eq(op[2], "d1-1789000000.o", "d1 收的是這次的快照");
}

void test_source_must_serve_its_term(object ob)
{
	mixed *ops;

	//  d7 這格空著，但 d1 才三小時大 —— 不該因為下一格空著就急著推。
	//  少了這一關，剛開始跑的頭一個小時就會把幾分鐘前的東西塞滿三格。
	ops = ob->plan_cascade(
		({ "1789000000.o", sprintf("d1-%d.o", NOW - 3 * 3600) }),
		"1789000000.o", NOW);
	expect_eq(op_for(ops, "d7"), 0, "來源沒在上一格待滿就不該往下推");
}

void test_moved_tier_is_not_also_deleted(object ob)
{
	mixed *ops;
	int i;

	//  d1 剛被推去 d7，就不該在同一輪又被當成過期的 d1 刪掉。
	ops = ob->plan_cascade(
		({ "1789000000.o", sprintf("d1-%d.o", NOW - DAY) }),
		"1789000000.o", NOW);
	for( i = 0; i < sizeof(ops); i++ )
		expect_true(!(ops[i][0] == "rm" &&
			ops[i][1] == sprintf("d1-%d.o", NOW - DAY)),
			"同一輪裡被搬走的檔不該又被刪一次");
}

void test_survives_empty_input(object ob)
{
	expect_eq(sizeof(ob->plan_cascade(0, "1789000000.o", NOW)), 0,
		"檔名清單是 0 時不該爆掉");
}

//  ------------------------------------------------------------------
//  對外查詢
//  ------------------------------------------------------------------

void test_unknown_player_has_no_snapshots(object ob)
{
	expect_eq(sizeof(ob->query_snapshots("nosuchplayerxyz")), 0,
		"沒有這個玩家就回空陣列，不是 0");
	expect_eq(ob->find_body_dir("nosuchplayerxyz"), 0,
		"找不到軀殼快照目錄時回 0");
	expect_eq(ob->find_link_dir("nosuchplayerxyz"), 0,
		"找不到連線快照目錄時回 0");
}

void test_bad_arguments_are_refused(object ob)
{
	expect_eq(ob->snapshot_dir(0), 0, "沒有物件時不該算出路徑");
	expect_eq(ob->take_snapshot(0), 0, "沒有軀殼就不該留快照");
	expect_eq(ob->find_body_dir(""), 0, "空名字要擋掉");
	expect_eq(ob->restore_snapshot("", "", 0), 0, "空名字不該還原任何東西");
}

//  節流值一定要小於 AUTOSAVE（23 分鐘），不然定時存檔會被自己擋掉，
//  近期環就只剩登入登出那幾份。
void test_gap_is_shorter_than_autosave(object ob)
{
	expect_true(ob->query_gap() < 23 * 60,
		"快照節流必須短於 AUTOSAVE，否則定時存檔留不下快照");
}
