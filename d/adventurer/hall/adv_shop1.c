#include <mudlib.h>

inherit ROOM;

void create()
{

	::create();
	set_short("小房間");
	set_long( @C_LONG_DESCRIPTION
你來到了冒險工具專賣店旁的一個小房間，地面上滿是被裁切過的毛皮碎片。
房間的中間放著一張工作臺，桌上放著一些未完成的防具或衣服，一個女裁縫
師坐在桌邊，正在努力的工作。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "objects", ([
	             "woman" : "/d/adventurer/hall/monsters/woman"
	                                         ]) );
	set( "exits", ([
	             "east" : "/d/adventurer/hall/adv_shop",
	                                         ]) );
        reset();       
}

