#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("火山山腳下");
	set_long( 
@LONG_DESCRIPTION
你站在一座巨大的火山山腳下，那聳立雲霄的火山山口似忽還會有陣陣濃煙
冒出，不知何時還會再爆發，你覺的這裡非常的熱，不可能有生物能在這裡生存
下去，這裡到處都是火山岩和浮石，這座由火山岩所構成的火山(volcano)，由於
到處是巨大的裂縫，因此想到達山頂是相當困難的。
LONG_DESCRIPTION
	);

set("item_desc",([
    "volcano" : "這座火山非常的高，以你的能力可能無法爬上去。\n",
       ]));
set( "exits", ([
     "south" : ONEW"wild20",
     "southwest" : ONEW"wild17",
     ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_climb","climb");
}

int do_climb()
{  if( random( (int)this_player()->query_skill("climbing") ) < 50 ) {
      write( 
         "想爬上去，門兒都沒有!\n");
      return 1;
    };
    write(
          "你使出吃奶的力氣終於爬了上去。\n");
    this_player()->move_player( ONEW"varea2.c","SNEAK" );
    return 1;
}
