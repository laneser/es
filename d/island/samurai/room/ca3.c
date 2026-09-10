#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "嘹望臺" );
   set_long(@ANGEL
你走進一個嘹望臺，這是武士城堡位置最高的地方，在這裡可以清楚的看到
武士城堡的四周圍狀況，可說是最重要的預警系統，如果這裡沒有人看守的話，
那就算是敵人攻到眼前可能也無人發現．
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard2"
	        ]) );
        set( "exits", ([
    "down"  :MR"ca1",
                ]) );
         reset();                     
#include <replace_room.h>
}

