#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Black Mace","黑色釘頭槌");
        add("id",({"mace",}) );
       set_short("黑色釘頭槌");
       set_long(
         "由米蘇理和銀混合製成的黑色釘頭槌.\n"
               );
	
	set( "unit", "把" );
 	set( "weapon_class", 30 );
    set("type","blunt");
	set( "min_damage", 19 );
	set( "max_damage", 36 );
	set( "weight", 180 );
	set( "value", ({ 400, "gold" }) );
}
