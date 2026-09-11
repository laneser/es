#include "mercury.h"
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "柵門" );
   set_long(@ANGEL
在你的面前是一個大的鐵柵門，是要進入武士城堡必經之關卡，是武
士城堡交通的樞紐．
ANGEL

   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "south" :MR"cac02",
    "north" :MR"cac04"
                ]) );
      create_door("north","south",([
                  "keyword" : ({"door","iron door"}),
                  "status"  : "closed",
                  "name"    : "Iron Door",
                  "c_name"  : "鐵柵門",
                  "c_desc"  : "一個鐵做的柵門\n"
                  ]) );
                            
         reset();                     
}

