#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "石碣村" );
	set_long(
	"這裡是梁山泊外的小漁村－石碣村，村中居民並不多，大約只有\n"
	"五六家，家家門口都曬著許多魚網(net)或漁具，也許這兒的居民通通\n"
	"都靠打漁維生。\n"
	  );
	set_outside("eastland");
        set("c_item_desc",(["net":
"這些是再普通不過的魚網，這兒的居民們利用它來捕捉湖中的水產以維\n"
"持生計。\n"
            ]));        
        set( "exits", ([
                "north" : TROOM"fish_plate",
                "east"  : TROOM"room1",
                "west"  : TROOM"room3",
                "south" : TROOM"village1"
        ]) );
        set( "objects",([
                "merchant" : "/d/eastland/haiwei/monster/merchant"
        ]));
        reset();
}
