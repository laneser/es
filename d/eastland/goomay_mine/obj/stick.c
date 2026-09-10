#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wooden stick", "柺杖" );
	add( "id", ({ "stick" }) );
   set_short( "柺杖" );
	set_long(
		"這是一根用堅硬的木頭做成的柺杖，目的是讓行動不方便\n"
		"的人使用的。\n"
	);
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "weapon_class", 14 );
	set( "min_damage", 8 );
	set( "max_damage", 16 );
	set( "weight", 100 );
	set( "value", ({ 230, "silver" }) );
}
