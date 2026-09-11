#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "天王大道" );
	set_long(
	"這山寨內竟有一條街道，一條以整齊的青石板鋪成的，不折不扣的街\n"
	"道．據說是為了紀念第一代老大: 托塔天王晁蓋而命名．街道兩旁，有各\n"
	"色各樣的店鋪，每一間店鋪的生意都好的很，只不過店鋪的門外，都沒有\n"
	"招牌．北邊有一個大廣場．\n"
	);
	set( "light",1 );
        set_outside( "eastland" );
        set( "no_monster",1);
        set( "exits", ([
                "east" : TROOM"store",
                "south"  : TROOM"path1",    
                "north"  : TROOM"flag",
                "west" : TROOM"wineshop"
        ]) );
}
int clean_up() { return 0; }