#include "mercury.h"

inherit ROOM;

void create()
{
   ::create();
   set_short( "武士城堡大門" );
   set_long(@ANGEL
這裡是武士城堡的入口，你可以看見旁邊高聳的城牆及全副武裝的衛兵，為了防禦
敵人的入侵這裡時時刻刻都配置著強大了兵力，向北可以進入武士城堡，南邊則是一個
哨站    
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
	set("objects",([
	    "yark":MOB"yark",
	    "guard#1":MOB"guard2",
	    "guard#2":MOB"guard2"
	      ]) );
        set( "exits", ([
                "north"  :MR"cac01",
                "south" :MR"station",
                ]) );
         reset();                     
}

