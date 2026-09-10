#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("sharp dagger","鋒利匕首");
       add("id",({"dagger",}) );
       set_short("鋒利匕首");
       set_long(
           "一把鋒利的匕首,可以保護自己\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 14 );
    set("type","dagger");
	set( "min_damage", 7 );
	set( "max_damage", 14 );
	set( "weight", 35 );
	set( "value", ({ 30, "gold" }) );

}
