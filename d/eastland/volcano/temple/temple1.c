#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("矮靈族神殿");
	set_long(
@LONG_DESCRIPTION
一間迷漫著神秘氣氛的矮靈族神殿，這裡是正殿，正殿的頂端雕有火神的圖案，
四根雕有龍紋的巨大柱子豎在四個腳落，前面似乎有一些人在那兒，距離太遠了
你看不清楚他們在做什麼，也不知道這個正殿供奉什麼神。
LONG_DESCRIPTION
	);
set( "exits", ([
     "north": OTEMP"temple4",
     "east": OTEMP"temple3",
     "west": OTEMP"temple2",
     "out" : OGROUP"warea16",
     ]) );
set("light",1);
reset();
#include "../replace_room.h"
}
