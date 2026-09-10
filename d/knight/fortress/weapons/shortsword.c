#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name( "short sword", "短劍" );
	add( "id", ({ "sword" }) );
	set_short( "鋼鑄短劍" );
	set_long(
		"這種鋼鑄短劍是諾頓騎士團的隨從們，隨身攜帶的武器。\n"
	);
	set( "unit", "把" );
	set( "type", "shortblade" );
	set( "weapon_class", 11 );
	set( "min_damage", 4 );
	set( "max_damage", 9 );
	set( "weight", 50 );
	set( "value", ({ 120, "silver" }) );
}
