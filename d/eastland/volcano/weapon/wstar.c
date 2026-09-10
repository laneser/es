#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("wraith morningstar","矮靈流星□");
       add("id",({"morningstar","star"}) );
       set_short("矮靈流星□");
       set_long(
           "一把矮靈流星□\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class",27 );
        set( "type","chain");
	set( "min_damage", 13 );
	set( "max_damage", 30 );
	set( "weight", 100 );
	set( "value", ({ 300, "gold" }) );
}
