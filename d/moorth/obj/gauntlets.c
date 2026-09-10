#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed gauntlets", "合金護手" );
	add( "id", ({ "gauntlets" }) );
	set_short( "a pair of alloyed gauntlets", "合金護手" );
	set_long(
		"You see a pair of alloyed gauntlets. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"這是一雙用某種不知名合金打造的護手，看起來相當重。\n"
	);
	set( "unit", "雙" );
	set( "type", "hands" );
	set( "material", "heavy_metal");
	set( "armor_class", 5 );
	set( "weight", 80 );
	set( "value", ({ 760, "silver" }) );
}
