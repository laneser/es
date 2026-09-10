#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("yanling blade","雁翎刀");
       add("id",({"blade"}) );
       set_short("雁翎刀");
	   set_long(
           "這是綠林好漢最喜愛的刀子，因為它非常好使，威力也不錯．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 30 );
        set("type","longblade");
	set( "min_damage", 15 );
	set( "max_damage", 33 );
	set( "weight", 70 );
	set("bleeding",5);
	set( "value", ({ 90, "gold" }) );
	
}	
