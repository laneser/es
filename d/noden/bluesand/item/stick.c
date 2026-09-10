#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "wooden stick", "柺杖" );
	add( "id", ({ "stick" }) );
   set_short( "木質柺杖" );
	set_long(
		"這是一根用堅硬的木頭做成的柺杖。\n"
	);
	set( "unit", "把" );
	set( "type", "blunt" );
	set( "weapon_class", 8 );
	set( "min_damage", 4 );
	set( "max_damage", 8 );
	set( "weight", 60 );
	set( "value", ({ 130, "silver" }) );
}
