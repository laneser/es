#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "iron blade", "鐵刀" );
	add( "id", ({ "blade" }) );
	set_short( "鐵刀" );
	set_long(
		"這是一把用生鐵鑄成的刀子，看來有點粗製爛造的。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 50 );
	set( "weapon_class", 15 );
	set( "min_damage", 7 );
	set( "max_damage", 14 );
	set( "value", ({ 220, "silver" }) );
}
