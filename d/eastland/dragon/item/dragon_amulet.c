#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Amulet of Dragon", "龍之紋章" );
	add( "id", ({ "amulet", }) );
	set_short( "孽龍紋章" );
	set_long(
		"這是一面象徵屠龍的紋章。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material" ,"cloth" );
        set( "defense_bonus", 2 );
        set( "special_defense", ([ "fire":3 ]) );
	set( "extra_look", "$N帶著象徵屠龍的紋章。\n" );
	set( "no_sale", 1 );
	set( "weight", 15 );
	set( "value", ({ 100, "silver" }) );
}
