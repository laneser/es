#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("curved knife","彎曲的小刀");
       add("id",({"knife",}) );
       set_short("彎曲的小刀");
       set_long(
     	 "一把彎曲的小刀.\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 7 );
    set("type","dagger");
	set( "min_damage", 4 );
	set( "max_damage", 7 );
	set( "weight", 32 );
	set( "value", ({ 70 , "silver" }) );

}
