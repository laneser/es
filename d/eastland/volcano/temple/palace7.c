#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";
inherit DOORS;

void create()
{
	::create();
	set_short( "小龍女寢宮" );
	set_long(
@LONG
這裡是龍王的獨生女－蘭心的寢宮，房間中瀰漫著一片淡淡的清香，鵝黃色
的被子，粉色的床，牆壁是淡淡的紫色，梳妝檯上放了一些小飾品、一把梳
子和一隻繡花針。
LONG
	);
	set( "exits", ([
	     "south" : OTEMP"palace5",
	]) );
        create_door("south","north", ([
                    "keyword" : ({"door","diamond door"}),
                    "name" : "diamond door",
                    "c_name" : "鑽石大門",
                    "status" : "locked",
                    "lock" : "DIAMONDKEY",
                    "desc" : "A door made of diamond",
                    "c_desc" : "一扇用整塊鑽石切割而成的門"
                    ]) );
         set("light",1);
         set("objects", ([
             "princess":OMONSTER"princess",
             ]) );
         reset(); 
}
