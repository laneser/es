//  File     : /std/room/room.spec.c
//  /std/room/room.c 的 spec —— 全站房間（含虛擬房間的 TEMPLATE）都是它。
//  06-09-11 建立

#include <lest.h>

inherit SPEC;

void test_exits(object room)
{
	room->set("exits", ([ "east" : "/d/std/rooms/void",
	                      "west" : "/d/std/rooms/netdead" ]));
	expect_true( room->valid_exit("east"), "設過的出口應該有效" );
	expect_true( room->valid_exit("west"), "設過的出口應該有效" );
}

void test_invalid_exit(object room)
{
	room->set("exits", ([ "east" : "/d/std/rooms/void" ]));
	expect_true( !room->valid_exit("up"), "沒設過的方向不該是有效出口" );
}

void test_no_exits_at_all(object room)
{
	//  沒有 exits 這個 key 時 valid_exit 不該炸，只該回假
	expect_true( !room->valid_exit("north"), "完全沒設 exits 時應該安靜回假" );
}

void test_short_and_long(object room)
{
	room->set_short("測試房間");
	room->set_long("這是一個 lest 用的房間。\n");
	expect_eq( room->query("short"), "測試房間", "短描述" );
	expect_string( room->query("long"), "長描述不可為空" );
}

void test_light(object room)
{
	room->set("light", 1);
	expect_eq( room->query("light"), 1, "亮度屬性" );
}
