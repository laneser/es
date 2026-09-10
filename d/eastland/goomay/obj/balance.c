#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "balance beam", "大桿秤" );
	add( "id", ({ "beam" }) );
	set_short( "a balance beam", "大桿秤" );
	set_long(
		"You see a balance beam for trading.\n",
		"這是一把大號的桿秤，專門用來秤特大號的貨物用的。\n"
	);
	set( "unit", "把" );
	set( "weight", 200 );
	setup_weapon( "polearm", 25, 15, 30 );
	set( "value", ({ 420, "silver" }) );
}
