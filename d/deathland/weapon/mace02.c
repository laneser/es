#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Mithril Mace","米蘇里釘頭槌");
        add("id",({"mace",}) );
       set_short("米蘇里釘頭槌");
       set_long(
         "一把米蘇里釘頭槌.\n"
               );
	
	set( "unit", "把" );
 	set( "weapon_class", 24 );
       set("type","blunt");
	set( "min_damage", 15 );
	set( "max_damage", 30 );
	set( "weight", 180 );
	set( "value", ({ 170, "gold" }) );
}
