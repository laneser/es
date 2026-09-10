#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("草地");
	set_long( 
@LONG_DESCRIPTION
這裡沒有明顯的路給你走，你站在一大片草地中間，草地呈黃綠色，每當有風吹
過，所有的草就隨風左右搖曳，如同海浪一般，仔細觀察地面似乎有幾個小地洞，可
能是土撥鼠之類的動物，在這裡建造它們的房子；在這危險的地方，風聲鶴唳，稍微
有點風吹草動，都會使人驚心膽顫。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "southwest" : ONEW"wild7",
     "southeast" : ONEW"wild11", ]) );
set( "objects", ([
     "worm":OMONSTER"worm",
     ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
