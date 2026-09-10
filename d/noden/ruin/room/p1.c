// p1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("卡榭布蘭卡宮．正殿");
    set_long(@C_LONG
映入你眼簾的是一個寬敞幽靜的大廳。地板是由閃閃發亮的紫水晶與藍寶
石鋪設而成，四周的牆壁和天花板上滿布著美麗的壁畫和精緻的石雕。女王的
王座端正地立於北邊的臺階上，周圍有著神奇的魔法力量拱衛著。
C_LONG
	    );
    set("exits", ([
	"south" : AREA"p0"
	]));
    set("objects", ([
	"queen" : MOB"queen",
	"emerald" : MOB"emerald"
	]));
    reset();
}


