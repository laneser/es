#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮靈族神殿");
	set_long( 
@LONG_DESCRIPTION
一間迷漫著神秘氣氛的矮靈族神殿正殿，正殿的頂端雕有火神的圖案，一根
有龍紋的巨大柱子(post)豎在腳落，牆壁上雕滿了許多奇怪的花紋，地板是用一
塊塊的火山岩拼成的。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northwest": OTEMP"temple9",
     "east": OTEMP"temple4",
     "south": OTEMP"temple2",
     ]) );
set("item_desc",([
    "post" : @POST
一條騰雲駕霧的紫龍，全身是暗紫色的，一層層的紫色鱗片閃閃發亮，兩眼炯
炯有神的看著你。
POST
       ]));
set("light",1);
reset();
#include "../replace_room.h"
}
