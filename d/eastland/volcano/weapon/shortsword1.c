#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("wraith shortsword","矮靈短劍");
       add("id",({"shortsword"}) );
       set_short("矮靈短劍");
       set_long(
           "一把由火山岩所制的矮靈短劍\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
        set( "type","shortblade");
        set( "second",1);
	set( "min_damage", 10 );
	set( "max_damage", 30 );
	set( "weight", 200 );
	set( "value", ({ 500, "gold" }) );
}
