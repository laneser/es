#include "../nodania.h"

inherit WEAPON;

void create()
{
	seteuid(getuid());
	set_name("sabre", "佩劍");
	add( "id", ({ "sword" }) );
	set_short("諸神的佩劍");
	set_long(
		"這是諸位大神們隨身攜帶的佩劍。\n"
	);
	set( "unit", "把" );
	set( "weight", 10 );
// Only wizards or monsters can wield this weapon.
	set( "weapon_class", 99 );
	set( "type", "longblade" );
	set( "min_damage", 9 );
	set( "max_damage", 99 );
	set( "value", ({ 300, "platinum" }) );
	set( "no_sale", 1 );
}
