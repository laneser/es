#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("pike", "長槍");
	set_short("長槍");
	set_long(
		"這是一種在長柄木杖末端裝上槍頭的輕便武器。\n"
	);
	set( "unit", "把" );
	set( "weight", 60 );
	set( "type", "polearm" );
	set( "weapon_class", 14 );
	set( "min_damage", 6 );
	set( "max_damage", 16 );
	set( "nosecond", 1 );
	set( "value", ({ 500, "silver" }) );
}
