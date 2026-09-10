#include "../farwind.h"

inherit ARMOR;

void create()
{
	set_name("leather boots", "皮靴");
	add( "id", ({ "boots" }) );
	set_short("皮靴");
	set_long(
		"這雙皮製的長靴能保護穿著者的腳部。\n"
	);
	set( "unit", "雙" );
	set( "type", "feet" );
	set( "material", "leather");
	set( "armor_class", 6 );
	set( "defense_bonus", 0 );
    set( "special_defense",
               ([ "cold":3, "fire":-3, "acid":2 ]) );
	set( "weight", 30 );
	set( "value", ({ 48, "gold" }) );
}
