#include "takeda.h"


inherit WEAPON;

void create()
{
       set_name("scythe-lance","鉤鐮槍");
       add("id",({"lance"}) );
       set_short("鉤鐮槍");
	   set_long(
           "這是一把造型奇特的槍，末端連著一把小鐮刀．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 26 );
        set("type","thrusting");
	set( "min_damage", 21 );
	set( "max_damage", 28 );
	set( "weight", 130 );
	set( "value", ({ 42, "gold" }) );
        set( "nosecond",1);
}
	
