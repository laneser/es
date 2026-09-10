#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "abacus", "算盤" );
	add( "id", ({ "counter" }) );
	set_short( "算盤" );
	set_long(
		"這是一個烏黑的算盤，只是一般商業用的，看起來不像是武器。\n"
	);
	set( "unit", "個" );
	set( "weight", 100 );
	setup_weapon( "blunt", 25, 10, 20 );
	set( "value", ({ 20, "gold" }) );
        set_c_verbs(({"%s砸向%s","%s推向%s","%s撞向%s"}));

}
