#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("waraxe", "戰斧");
	add( "id", ({ "axe" }) );
        set_short( "戰斧" );
	set_long(
		"這種沉重的戰斧是專為強壯的戰士設計的。\n"
	);
	set( "unit", "把" );
	set( "weight", 110 );
	set( "no_second", 1 );
	setup_weapon( "axe", 17, 10, 20 );
	set( "bleeding", 10 );
	set( "value", ({ 680, "silver" }) );
}
