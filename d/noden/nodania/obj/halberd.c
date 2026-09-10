#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("halberd", "長戟");
	set_short("鋼製長戟");
	set_long(
		"這種長戟通常是諾頓皇家騎士團的騎士所喜愛的武器。\n"
	);
	set( "unit", "把" );
	set( "weight", 160 );
	set( "type", "polearm" );
	set( "weapon_class", 30 );
	set( "min_damage", 15 );
	set( "max_damage", 38 );
	set( "nosecond", 1 );
	set( "value", ({ 1900, "silver" }) );
}
