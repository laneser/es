//File: book_temple1.c 藏經閣前空地

#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "藏經閣前" );
       set_long( @C_LONG_DESC
你走到一條小河邊，河邊矗立著一棟樓閣，原來這就是大名鼎鼎的少林寺藏
經閣(library)，武林中人夢寐以求的武學寶庫。你很想進去(enter)見識見識，
可是閣旁四周不起眼處三兩武僧看似悠閒的站在一起，他們一定是守護藏經閣的
僧人，看他們一個個神完氣足，太陽穴高高鼓起，想必都是內外兼修的高手。孤
零零的一棟藏經閣建在河邊，既防火警又可防盜，實在是高明之極。
C_LONG_DESC
        );
        set( "objects",([
            "monk1" : SAULIN_MONSTER"book_guard",
            "monk2" : SAULIN_MONSTER"book_keeper"  ]));
        set_outside("eastland");
    set("exits",([
       "west"  : SAULIN"stone_path2",
       "north" : SAULIN"river_side3",
       "south" : SAULIN"river_side4",
    ]) );
    reset();
}

void init()
{
    add_action( "enter_library", "enter" );
}

int enter_library(string arg)
{
	if( !arg || arg != "library" )
   		return notify_fail("你想進哪兒去啊？\n");
 	if( (present("guardian") || present("keeper") ) && (!wizardp(this_player())) &&
 		     (!this_player()->query_temp("book_quest/step")) ) {
      tell_object(this_player(),@ENTER_LIB
你正想大搖大擺的走進藏經閣，突然守閣僧人走了過來對你合十道：
    藏經閣為本寺重地，施主請勿擅闖 !!
他們又向你微微躬身，身上的僧衣突然股了起來，你只覺得一陣強勁
的力道向你壓來，忍不住連退了三四步。
ENTER_LIB
);
      return 1;
	} else {
      tell_object(this_player(), 
      	"現在沒有人再能阻止你了，你大搖大擺的走進藏經閣。\n");
      this_player()->set_temp("book_quest/step",0);
	  this_player()->move_player(SAULIN"book_temple2","SNEAK");
	  return 1;
	}
}
