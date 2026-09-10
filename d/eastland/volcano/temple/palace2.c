#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "龍宮大殿" );
	set_long(
@LONG_DESCRIPTION
這是井龍宮的大殿，雖然不大但仍有一股氣勢在，這裡比起陸上皇帝的宮殿
不知華麗幾千倍，文臣武將列在兩旁，他們正以一種奇怪的眼神看著你，往
前望去，似乎有人高高的坐在上面。
LONG_DESCRIPTION
	);
	set( "exits", ([
             "south" : OTEMP"palace1",
	     "north" : OTEMP"palace3",
	]) );
        set ("objects", ([
             "fish_scholar":OMONSTER"fish_scholar",
             "fish_general":OMONSTER"fish_general",
             ]) );
        set("light",1);
        reset();
}
