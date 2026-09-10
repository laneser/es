// lib3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("大圖書館．長廊");
    set_long(@C_LONG
你現在身處於一條長長的走廊上，大理石鋪成的走道向東西方向延伸。兩旁  
的牆壁上畫著許多奇怪的圖案，似乎是某種塗鴨。長廊的牆壁不知是用什麼東西
所建造的，閃耀著淡淡的光芒。
C_LONG
    );
    set("exits", ([
	"west" : AREA"lib2",
	"east" : AREA"lib4"
	]) );
    set("item_desc", (["wall" : "牆上畫著一個盾，筆法很是拙劣。\n"]) );
    set("light", 1);
    reset();
}


