#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "blacksteel grand axe", "闊斧" );
	add( "id", ({ "axe", "grand axe", "blacksteel axe" }) );
	set_short( "a blacksteel grand axe", "鑌鐵闊斧" );
	set_long(
		"You see a blacksteel grand axe.\n",
		"一把用堅硬的鑌鐵鑄成的闊斧。\n"
	);
	set( "unit", "把" );
	set( "type", "axe" );
	set( "weapon_class", 30 );
	set( "min_damage", 22 );
	set( "max_damage", 36 );
	set( "weight", 340 );
	set( "value", ({ 730, "silver" }) );
	set( "nosecond", 1 );
	set( "no_sale", 1 );
}
