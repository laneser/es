#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short("石室");
	set_long( 
@LONG_DESCRIPTION
你正在一個黑黝黝的石室中，這裡到處是殘骨斷骸，血跡斑斑．．．．．．．．．
看了就教人心驚膽跳。
LONG_DESCRIPTION
	);
set( "exits", ([
     "east" : OGROUP"tunnel1",
     ]) );
set( "objects", ([
     "shuang":OMONSTER"shuang",
     ]) );
reset();
}
