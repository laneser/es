#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("white morningstar","白流星槌");
       add("id",({"morningstar",}) );
       set_short("a white morningstar","白流星槌");
       set_long(
           "一把白色流星槌\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 22 );
    set("type","chain");
	set( "min_damage", 11 );
	set( "max_damage", 23 );
	set( "weight", 210 );
	set( "value", ({ 100, "gold" }) );
}
