#include <takeda.h>

inherit WEAPON;

void create()
{
	set_name("wood oar", "棗木槊");
	add("id",({"oar"}));
	set_short("棗木槊");
	set_long(
		"這是一把棗木製的大船槳，給它打上一下可不好玩。\n"
	);
	set( "unit", "根" );
	set( "weight", 170 );
	set( "type", "blunt" );
	set( "weapon_class", 20 );
	set( "min_damage", 12 );
	set( "max_damage", 23 );
	set( "value", ({ 610, "silver" }) );
}
