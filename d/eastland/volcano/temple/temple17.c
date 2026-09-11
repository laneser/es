#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿左殿");
	set_long(
@LONG_DESCRIPTION
一間迷漫著神秘氣氛的矮靈族神殿左殿，神殿的頂端雕有火麒麟的圖案，
這裡供奉的是火麒麟，在矮靈族的傳說中火麒麟是火神的坐騎之一。牆壁上有
著一幅壁畫，描寫矮靈族中歡樂的景象。坐在宴席上的貴賓，右側是男女奴隸
，打扮的□麗非常，手拿著蓮花伺候著；女奴頭上戴有玉蜀黍狀的飾物，正在
為客人倒酒。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple9",
     ]) );
set ( "objects", ([
      "l_enforcer":OMONSTER"l_enforcer",
      "wprayer":OMONSTER"wprayer"
      ]) );
set("light",1);
reset();
#include "../replace_room.h"
}
