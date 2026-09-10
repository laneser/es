#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "lizardman shortsword", "蜥蜴人短劍" );
	add( "id", ({ "sword","shortsword" }) );
	set_short( "蜥蜴人短劍" );
	set_long(@LONG
一把木質劍柄的短劍，它似乎並不是很鋒利，但適合砍擊。
LONG
	);
	set( "unit", "把" );
	set( "type", "shortblade" );
	set( "weapon_class", 15 );
	set( "min_damage", 8 );
	set( "max_damage", 19 );
	set( "weight", 90 );
	set( "value", ({ 150, "silver" }) );
}
