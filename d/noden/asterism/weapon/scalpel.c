#include "../asterism.h"

inherit WEAPON;

void create()
{
       set_name("scalpel","手術刀");
       add("id",({"dagger",}) );
       set_short("手術刀");
       set_long(
     	 "一把專門在手術時使用的小刀.\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 24 );
    set("type","dagger");
	set( "min_damage", 15 );
	set( "max_damage", 24 );
	set( "weight", 32 );
	set( "value", ({ 1900 , "silver" }) );

}
