#include <mercury.h>
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川樓大門" );
   set_long(@ANGEL
在你的面前是武士城堡的指揮中心千川樓的入口，整個大樓有個很濃厚
的日本式風味，你還可以聞到一股黑檀木的香味，似乎千川樓用了許多的黑
檀木為建材，在大樓的四周種了兩排的櫻花樹，使的整間大樓看起來好像在
樹林裡一樣．
ANGEL

   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard2",
	        "guard2":MOB"guard2",
	        ]) );
        set( "exits", ([
    "south" :MR"inn02",
    "north" :MR"inn04",
    "west"  :MR"tree01"
                ]) );
      create_door("north","south",([
                  "keyword" : ({"door","ebony door"}),
                  "status"  : "closed",
                  "name"    : "Ebony Door",
                  "c_name"  : "黑檀木門",
                  "c_desc"  : "一個用黑檀木做門，上面用精細的手工\n"
                              "雕出一條華麗的龍\n"
                  ]) );
                            
         reset();                     
}

