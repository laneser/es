#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("拱橋");
	set_long( @LONG
你正立足在一座通體水晶建成的拱橋上，拱橋到這裡已經是湖中心位置了。拱
橋雕鏤精細，巧奪天工，銀光燦爛，耀眼生花。橋底下是面波平如鏡，碧水浩蕩的
百畝圓湖；湖面錦麟遊泳，綠波鱗鱗；沿岸瓊枝瑤草，青樹琪花，搖搖曳曳。橋下
一座古色古色的六角涼亭，四面碧玉欄楣，青杆綠柱，周圍繁花綠葉，清絕天上人
間。
LONG
	);
        set("light",1);
        set("exits" , ([
             "down" : SPALACE"rest1",
             "east" : SPALACE"bridge1",
        ]) );
	reset();
}
