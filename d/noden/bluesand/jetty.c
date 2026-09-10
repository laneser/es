#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
   set_short("藍沙港碼頭");
	set_long( @LONG_DESCRIPTION
這裡是藍沙港的碼頭，規模雖然不是很大，但是諾頓王國和東方大國
的貿易幾乎都要經過這裡，在碼頭上你可以看到各式各樣的船隻(ship)與
箱子(boxes)，裡面裝的大部分都是來自東方的貨品，只有少部份是諾頓王
國的貨物。
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "light", 1 );
	set( "c_item_desc", ([ 
		"ship" : @LONG_TEXT
這些船只有的雙桅，有的三桅，看起來都是建造成適合遠航的樣子，你注意
到一艘用白漆在船身漆著「比亞藍號」的船停泊在碼頭的東邊不遠處，如果
你會游泳(swim)，也許可以游過去看看。\n
LONG_TEXT
, 
		"boxes" : "這些箱子整整齊齊地堆在碼頭上，等待碼頭工人過來搬運。\n" ]) );
    set( "exits", ([ 
		"west" : "/d/noden/bluesand/port_r2" ]) );
	set( "objects", ([
		"jeff" : "/d/noden/bluesand/monster/jeff" ]) );
	reset();
}

void init()
{
	add_action("do_swim", "swim" );
	if( !find_object("/d/std/ocean/ship_iriah") )
		"/d/std/ocean/ship_iriah"->frog();
	if( !find_object("/d/std/ocean/ship_death") )
		"/d/std/ocean/ship_death"->frog();
}

int do_swim()
{
    int swim_skill;

	swim_skill = (int)this_player()->query_skill("swimming");
	if( random(swim_skill) < 20 ) {
            write(
                    "你喝了幾口又冷又鹹的海水，狼狽地爬回岸上。\n" );
            tell_room( this_object(),
this_player()->query("c_cap_name")+"跳進海里，用可笑的姿勢遊了幾公尺，然後狼狽地爬回岸上。\n",
			this_player() );
		return 1;
	}
   write(
"你跳進冰冷的海水，奮力向那艘船游去，終於抓到船身旁的纜繩，爬上船頭。\n" );
    tell_room( this_object(),
          this_player()->query("c_cap_name")+"跳進海里，遊向東邊的一艘船上。\n",
		this_player() );
	this_player()->move_player("/d/noden/bluesand/ship", "SNEAK");
	return 1;
}

