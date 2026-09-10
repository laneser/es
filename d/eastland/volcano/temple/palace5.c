#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";
inherit DOORS;

void create()
{
	::create();
	set_short( "stairway", "走廊" );
	set_long(
@LONG
你正漫步在井龍宮的走廊，一盞盞琉璃燈火懸在走廊的兩旁，在這裡你做什麼事
都得特別小心，否則會發生什麼事只有天知道。
LONG
	);
	set( "exits", ([
             "north" : OTEMP"palace7",
             "west" : OTEMP"palace3",
	     "east" : OTEMP"palace8",
	]) );
        create_door("north","south", ([
                    "keyword" : ({"door","diamond door"}),
                    "name" : "diamond door",
                    "c_name" : "鑽石大門",
                    "status" : "locked",
                    "lock" : "DIAMONDKEY",
                    "desc" : "A door made of diamond",
                    "c_desc" : "一扇用整塊鑽石切割而成的門"
                    ]) );
         set("light",1);
         reset(); 
}
