#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("草地上的小路");
	set_long( @LONG
你正站在一條玉製小路上，小路向西邊方向延伸，四周是綠草如茵，東邊一座
瓊樓高院，莊嚴豪麗，氣象萬千，瑤壁上嵌一白玉牌，內鑲二字漆金古篆文，其筆
力雄勁，書著「天都」二字。草地上各色繁花，花大如錢，偶一陣微風吹過，花隨
同披佛，漫天花香，清馨醒腦，沁人心脾。旁邊一玉製石階。
LONG
	);
	set("light",1);
        set( "exits", ([
              "up" : SPALACE"palace1",
            "west" : SPALACE"plain2"
        ]) );
	reset();
}
