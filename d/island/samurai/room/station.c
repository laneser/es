#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "哨站" );
   set_long(@ANGEL
這裡是武士城堡的入口前的一個哨站，是武士城堡防衛的第一線，但應屬於觀察
性質，所以看守的兵力並不多，往東走你可以離開武士城堡．    
ANGEL
   
         );
	set( "light",1);	
	set_outside("eastland");	
	set("objects",([
	    "guard1" :MOB"guard",
	    "guard2" :MOB"guard",
	    "soldier1" : MOB"soldier",
	    "soldier2" : MOB"soldier"
	    ])
	    );
        set( "exits", ([ 
   "north":MR"cac00",
   "east" :"/d/island/3,7.island"
                ]) );
         reset();                     
}

