#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bastard blade", "精鋼戒刀" );
	add( "id", ({ "blade" }) );
	set_short( "精鋼戒刀" );
	set_long(
		"這是一把用精鋼鑄成的超級大戒刀，是少林寺羅漢堂弟子慣用的兵刃。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 178 );
	set( "nosecond", 1 );
	set( "weapon_class", 30 );
	set( "min_damage", 20 );
	set( "max_damage", 30 );
	set( "value", ({ 600, "silver" }) );
}
