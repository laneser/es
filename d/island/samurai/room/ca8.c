#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "城牆" );
   set_long(@ANGEL
你走在一個武士城堡的外圍城牆的終點，這個位置正好是城門的上方，在
此可以攻擊城門的敵人，所以為了戰略的需求，這裡也配有重兵力！！
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");
	set( "objects", ([
	     "ekars" :MOB"ekars",
	     "guard1" :MOB"guard2",
	     "guard2" :MOB"guard2",
	          ]));
        set( "exits", ([
    "west" :MR"ca7",
                ]) );
         reset();                     
#include <replace_room.h>
}

