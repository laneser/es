#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Standard Longsword", "制式長劍" );
	add( "id", ({ "longsword","sword","standard" }) );
	set_short( "制式長劍" );
	set_long(
		"這是一把標準的長劍，不論長度或重量都很適合初學者使用。\n"
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weight", 80 );
	set( "weapon_class", 25 );
	set( "min_damage", 13 );
	set( "max_damage", 24 );
	set( "value", ({ 470, "silver" }) );
}
