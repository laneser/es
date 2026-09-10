#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bronze staff", "青銅禪杖" );
	add( "id", ({ "staff" }) );
	set_short( "青銅禪杖" );
	set_long( "這是一把用青銅鑄成的禪杖，看起來相當沈重。\n");
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "weapon_class", 14 );
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "weight", 140 );
	set( "value", ({ 240, "silver" }) );
}
