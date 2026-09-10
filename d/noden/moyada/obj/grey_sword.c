#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "sword of Grey", "葛雷之劍" );
	add( "id", ({ "sword", "longblade", "blade", }) );
	set_short( "葛雷之劍" );
	set_long( @C_LONG
冒險家葛雷最慣用的武器, 劍柄上刻著一條小小的青蛇, 莫非是蛇島的東西?
C_LONG
	);
	set( "unit", "把" );
	set( "weapon_class", 34 );
	set( "type", "longblade" );
	set( "min_damage", 18 );
	set( "max_damage", 30 );
	set( "no_sale", 1);
	set( "weight", 100 );
	set( "value", ({ 10930, "silver" }) );
}
