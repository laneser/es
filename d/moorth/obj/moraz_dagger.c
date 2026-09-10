#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "moraz dagger", "莫雷茲匕首" );
	add( "id", ({ "dagger" }) );
	set_short( "a moraz dagger", "莫雷茲匕首" );
	set_long(
		"This is a sharp moraz dagger.\n",
		"這是一把造型奇特的匕首，重量經過精密的計算與平衡，使得力量\n"
		"不大的人也可以用這把匕首輕易地削斷敵人的兵刃。\n"
	);
	set( "unit", "把" );
	set( "type", "dagger" );
	set( "weight", 30 );
	set( "weapon_class", 34 );
	set( "min_damage", 13 );
	set( "max_damage", 20 );
	set( "value", ({ 1270, "silver" }) );
	set( "no_sale", 1 );
}
