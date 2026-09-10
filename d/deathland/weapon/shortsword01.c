#include "../echobomber.h"

inherit WEAPON;

void create()
{
    set_name("Black shortsword", "黑色短劍");
    add("id",({"sword","shortsword"}) );
    set_short("黑色短劍");
    set_long(
         "這是矮人小孩所用的玩具短劍.\n"
    );
	
	set( "unit", "把" );
 	set( "weapon_class", 7 );
    set( "type","shortblade");
	set( "min_damage", 3 );
	set( "max_damage", 8 );
	set( "weight", 50 );
	set( "value", ({ 100, "silver" }) );
}
