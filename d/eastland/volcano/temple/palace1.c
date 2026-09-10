#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "龍宮門" );
	set_long(
@LONG_DESCRIPTION
你無法相信你現在所看到的，一座閃曜著碧綠色的光輝的宮殿，宮殿大門是用
珊瑚雕成，以一顆顆珍珠鑲在綠玉砌成的階梯上，屋頂的瓦片其實是紅玉，宮
門兩旁的柱子刻有龍的浮雕，龍的眼睛鑲有紫色的鑽石，宮門上面一塊白玉扁
額書寫著：井龍宮。
LONG_DESCRIPTION
	);
	set( "exits", ([
             "south" : OTEMP"well4",
	     "north" : OTEMP"palace2",
	]) );
        set("objects", ([
            "fish_soldier#1":OMONSTER"fish_soldier",
            "fish_soldier#2":OMONSTER"fish_soldier"
            ]) );
        set("light",1);
        reset();
}
