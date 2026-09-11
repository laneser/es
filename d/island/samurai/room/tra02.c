#include "mercury.h"
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "武士訓練場" );
   set_long(@ANGEL
你現在正在武士訓練場內，四周擺了好幾根擊劍用的木頭，還有幾把練
習用的木刀擺在一旁，一股濃濃的汗臭味刺激著你的鼻子，牆上掛著一幅字
畫(picture)．　
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "east" :MR"tra01",
    "west" :MR"tra04",
    "south":MR"tra03",
    "north":MR"tra07"
                ]) );
      create_door("east","west",([
                  "keyword" : ({"door","wooden door"}),
                  "status"  : "closed",
                  "name"    : "Wooden Door",
                  "c_name"  : "木門",
                  "c_desc"  : "一個木頭做的門\n"
                  ]) );
     set("c_item_desc",(["picture":@AAA
     你可以看到上面用著蒼建有力毛筆寫著:
     
     武士之道，永無止境
     
AAA
]));                            
         reset();                     
}

