// eda1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("城市廢墟");
    set_long(@C_LONG
你來到了一個破舊的廢墟，到處散落著頹圮的石柱和石塊。北方的不遠處
似乎有亮光，似乎是有人居住的樣子，說不定有出口呢！凜冽的冷風依然無情
地由四面八方吹來，令人感受到刺骨的寒意。
C_LONG
    );
    set("exits", ([ "north" : AREA"eda2" ]) );
    reset();
}

