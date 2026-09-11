#include "mercury.h"
inherit ROOM;

void create()
{
   ::create();
   set_short( "武士訓練場" );
   set_long(@ANGEL
你現在正在武士訓練場內，四周擺了好幾根擊劍用的木頭，還有幾把練
習用的木刀擺在一旁，一股濃濃的汗臭味刺激著你的鼻子　
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
    "soldier1" :MOB"soldier",
    "soldier2" :MOB"soldier",
    "soldier3" :MOB"soldier"
              ]));		
        set( "exits", ([
    "south":MR"tra02",
                ]) );        
         reset();                     
#include <replace_room.h>
}

