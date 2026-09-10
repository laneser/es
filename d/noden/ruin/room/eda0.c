// eda0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("城市廢墟");
    set_long(@C_LONG
你來到了一個破舊的廢墟，到處散落著頹圮的石柱和石塊。上方的洞口正
是你掉下來的地方，看來想從原路回去是不太可能的事。凜冽的冷風依然無情
地由四面八方吹來，令人感受到刺骨的寒意。
C_LONG
    );
    set("exits", ([ "north" : AREA"eda1" ]) );
    reset();
}


