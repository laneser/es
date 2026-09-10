#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "standard shortsword", "制式短劍" );
	add( "id", ({ "shortsword","sword","standard" }) );
	set_short( "制式短劍" );
	set_long(
            "這是一把標準的短劍，不論重量或是長度都很適合初學者使用。\n"
	);
	set( "unit", "把" );
	set( "type", "shortblade" );
	set( "weight", 50 );
	set( "weapon_class", 15 );
	set( "min_damage", 8 );
	set( "max_damage", 15 );
	set( "value", ({ 290, "silver" }) );
}
