#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("草地上的小路");
	set_long( @LONG
你正站在一條玉製小路上，小路向東邊方向延伸，四周是綠草如茵，西邊有一
玉製平臺。草地上各色繁花，花大如錢，偶一陣微風吹過，花隨同披佛，漫天花香，
清馨醒腦，沁人心脾，猶還染濡衣襟，沾了一身香氣。
LONG
	);
	set("light",1);
        set( "exits", ([
            "plate" : SPALACE"plain1",
             "east" : SPALACE"plain3"
        ]) );
	reset();
}
