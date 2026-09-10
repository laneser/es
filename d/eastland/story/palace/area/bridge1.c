#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("拱橋");
	set_long( @LONG
你正立足在一座拱橋上。拱橋通體水晶建成，雕鏤精細，巧奪天工，銀光燦爛
，耀眼生花。橋底下是面波平如鏡，碧水浩蕩的百畝圓湖；湖面錦麟遊泳，綠波鱗
鱗；沿岸瓊枝瑤草，青樹琪花，搖搖曳曳。橋旁一縷飛瀑自天際缺口急瀉而下，宛
如一條白色匹練。此間乃化外之境，超塵絕俗，令人流連忘返。

LONG
	);
        set("light",1);
        set("exits" , ([
             "down" : SPALACE"garden2",
             "west" : SPALACE"bridge2",
        ]) );
	reset();
}
