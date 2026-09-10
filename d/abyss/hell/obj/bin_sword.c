#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "blacksteel longsword", "長劍" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "a blacksteel longsword", "鑌鐵長劍" );
	set_long(
		"You see a blacksteel longsword.\n",
		"一把用堅硬的鑌鐵鑄成的長劍。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 30 );
	set( "min_damage", 14 );
	set( "max_damage", 27 );
	set( "weight", 140 );
	set( "value", ({ 620, "silver" }) );
	set( "no_sale", 1 );
}
