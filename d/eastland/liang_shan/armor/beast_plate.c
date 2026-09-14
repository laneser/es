#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("beast plate","連環獸面狻猊鎧");
    add("id",({"plate","mail"}) );
    set_short( "beast plate","連環獸面狻猊鎧");
	set_long(
		"This is a plate called best_plate....\n",
		"這是用一種叫狻猊的猛獸皮製成的戰甲，這種猛獸皮硬如石，生性\n"
		"兇猛，只有先拔下爪子挖去血肉才能得皮，因此這甲可是無價之寶．\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 350 );
	set( "type", "body" );
	set( "armor_class", 38 );
        set("material","leather");
	set( "defense_bonus", 6 );
	set( "value", ({ 275, "gold" }) );
}
