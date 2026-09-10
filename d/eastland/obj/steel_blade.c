#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "steel blade", "鋼刀" );
	add( "id", ({ "blade" }) );
   set_short( "鋼刀" );
	set_long(
		"這把鋼刀看起來十分尋常，寬背薄刃，重量趁手。\n"
	);
	set( "unit", "把" );
	set( "weight", 120 );
	setup_weapon( "longblade", 15, 10, 17 );
	set( "bleeding", 5 );
	set( "value", ({ 43, "gold" }) );
}
