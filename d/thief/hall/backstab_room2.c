#include <mudlib.h>
#include "../thief.h"
inherit ROOM;
#define TEST_ROOM "/d/thief/hall/backstab_room"
init()
{
	add_action("do_auc","auction");
	add_action("do_quit","quit");
}

do_auc()
{
	tell_object(this_player(),"你不能在這裡進行交易!!\n");
	return 1;
}

do_quit()
{
	TEST_ROOM->delete("begin_test");
	TEST_ROOM->delete("tester");
	TEST_ROOM->set("using",0);
        tell_object(this_player(),
                "一個聲音說道 : 放棄啦? 好吧, 下次再試試看可能比較好。\n");
//	TAYLERS->chat("測試訊息\n");
	return 1;
}

void create()
{
	::create();
	
	set("light", 1);
	set_short( "背刺測驗室" );
	set_long( @LONG
這是一間寬敞的房間，裡面擺滿了大大小小的箱子，很適合藏身，
是專門設計用來作為訓練場的。
LONG
	);

	set("exits", ([
		"north" : "/d/thief/hall/pathway",
		"south" : TEST_ROOM,
	]) );
	set("pre_exit_func",([
		"north" : "pass_test" ]) );
	reset();

/*
create_door("north","south",([
             "keyword" : ({"door" }),
             "status" : "locked",
             "c_desc" : "一扇結實厚重的鐵門",
             "c_name" : "鐵門",
             "name":"iron door",
             "desc":"an iron door",
             "lock" : "backstab_room2",
              ]) );

*/	
}

int pass_test()
{
	object *inv;
	int i;
	if ( present("maskman",this_object()) ) {
		tell_object(this_player(),
		"蒙面人伸手把你攔住，不讓你通過。\n");
		return 1;
	}
	if ( !this_player()->query_temp("pass_test") )	return 0;
	this_player()->delete_temp("pass_test");
	this_player()->delete_temp("skip_dead");
	this_player()->add("thief_level/backstab",1);

	TEST_ROOM->delete("begin_test");
	TEST_ROOM->delete("tester");
	TEST_ROOM->set("using",0);

	tell_object(this_player(),
		"你興奮地穿過鐵門。\n"
		"經過這次的戰鬥訓練，你的背刺能力提升到了第 "+this_player()->query("thief_level/backstab")+" 級 !!\n");
	TAYLERS->chat("恭喜" + this_player()->query("c_name") + "通過背刺測驗 !!");
	return 0;
}

