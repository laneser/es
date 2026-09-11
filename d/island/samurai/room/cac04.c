#include "mercury.h"

inherit DOORS;
inherit ROOM;

void create()
{
   ::create();
   set_short( "亞瑟斯路" );
   set_long(@ANGEL
你走在亞瑟斯路上，這是一個寬廣的大路，其路面是用堅硬的花崗石做的，道
路的北邊是寬廣的廣場．    
ANGEL
   
         );
	set( "light",1);
	set_outside("eastland");		
        set( "exits", ([
                "south"  :MR"cac03",
                "north" :MR"cac05",
                ]) );
         create_door("south","north",([
                     "keyword" : ({"door","iron door"}),
                     "status"  : "closed",
                     "name"    : "Iron Door",
                     "c_name"  : "鐵柵門",
                     "c_disc"  : "一個鐵做的柵門\n"
                     ]) );       
         reset();                     
}

