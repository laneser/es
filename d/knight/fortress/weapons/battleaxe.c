#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("steel battleaxe", "戰斧");
	add( "id", ({ "axe", "battleaxe" }) );
	set_short( "鋼鑄戰斧" );
	set_long(
		"這把戰斧看起來沈重、鋒利，是件戰士級的高級武器。\n"
	);
	set( "unit", "把" );
	set( "weight", 190 );
	setup_weapon( "axe", 31, 22, 35 );
	set( "bleeding", 10 );
	set( "value", ({ 980, "silver" }) );
}
