#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("long sword", "長劍");
	add( "id", ({ "sword" }) );
	set_short( "鋼鑄長劍" );
	set_long(
		"這種鋼劍是諾達尼亞侍衛隊的制式武器。\n"
	);
	set( "unit", "把" );
	set( "weight", 70 );
	set( "weapon_class", 18 );
	set( "type", "longblade" );
	set( "min_damage", 8 );
	set( "max_damage", 19 );
	set( "value", ({ 480, "silver" }) );
}
