#include "../echobomber.h"

inherit WEAPON;

void create()
{
	set_name("poet dagger","詩人匕首");
       add("id",({"dagger",}) );
       set_short("詩人匕首");
       set_long(
           "一把匕首,看起來很像一隻筆\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 14 );
    set("type","dagger");
	set( "min_damage", 7 );
	set( "max_damage", 16 );
	set( "weight", 25 );
	set( "value", ({ 450 , "silver" }) );

}
