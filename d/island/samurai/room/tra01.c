#include "mercury.h"
inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "武士訓練場入口" );
   set_long(@ANGEL
在你的面前是武士訓練場的入口，裡面則是所有武士團員都必須去的
地方，所有等級的武士都必須每天到此來上課及切磋武藝，由門內傳出濃
濃的汗臭可以瞭解武士們苦練的辛苦．　
ANGEL

   
         );
	set( "light",1);		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "east" :MR"cac07",
    "west" :MR"tra02"
                ]) );
      create_door("west","east",([
                  "keyword" : ({"door","wooden door"}),
                  "status"  : "closed",
                  "name"    : "Wooden Door",
                  "c_name"  : "木門",
                  "c_desc"  : "一個木頭做的門\n"
                  ]) );
                            
         reset();                     
}

