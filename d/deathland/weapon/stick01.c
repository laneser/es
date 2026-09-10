#include "../echobomber.h"

inherit WEAPON;

void create()
{
       set_name("wooden stick","木頭柺杖");
       add("id",({"stick",}) );
       set_short("木頭柺杖");
       set_long(
           "用木頭做成的柺杖\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 7 );
    set("type","blunt");
	set( "min_damage", 2 );
	set( "max_damage", 8 );
	set( "weight", 50 );
	set( "value", ({ 18, "silver" }) );

}
