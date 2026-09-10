#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("holy shortsword","神聖短劍");
        add("id",({"sword","shortsword"}) );
       set_short("神聖短劍");
       set_long(
         "一把神聖的短劍,據說是由神聖守衛使用的神兵利器 .\n"
               );
	
	set("no_sale",1);
	set( "unit", "把" );
 	set( "weapon_class", 35 );
 	set("second",1);
    set("type","shortblade");
	set( "min_damage", 22 );
	set( "max_damage", 33 );
        set( "weight",95 );
	set( "value", ({ 3000, "silver" }) );
}
