#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿右殿");
	set_long( 
@LONG_DESCRIPTION
一間迷漫著神秘氣氛的矮靈族神殿右殿，神殿的頂端雕有火龍的圖案。
這裡供奉的是火龍，在矮靈族的傳說中火龍是火神的坐騎之一，火龍有時也
會幻成人形出現。你看到牆上的壁畫描繪酒宴中的酋長，探險者，以及搬運
獵物的僕從，畫面洋溢著安詳和樂的氣氛。
LONG_DESCRIPTION
	);
set( "exits", ([
     "west": OTEMP"temple10",
     ]) );
set ("objects", ([
     "r_enforcer":OMONSTER"r_enforcer",
     "wprayer":OMONSTER"wprayer"
     ]) );
set("light",1);
reset();
#include <../replace_room.h>
}
