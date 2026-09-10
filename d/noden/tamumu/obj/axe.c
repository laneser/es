#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "grand axe", "巨斧" );
	add( "id", ({ "tamumu grand axe", "axe" }) );
	set_short( "塔姆姆巨斧" );
	set_long("這把巨斧的斧刃很寬，而且相當鋒利，能對敵人造成頗大的殺傷力。\n"
	);
	set( "unit", "把" );
	set( "type", "axe" );
	set( "weapon_class", 25 );
	set( "min_damage", 20 );
	set( "max_damage", 30 );
	set( "nosecond", 1 );
	set( "weight", 200 );
	set( "value", ({ 480, "silver" }) );
}
