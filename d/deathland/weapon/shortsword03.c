#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("break sword of Wind","風之斷劍");
        add("id",({"sword"}) );
       set_short("風之斷劍");
       set_long(
         "一把斷掉的神劍,據說它能隨著風而飛入敵人的心臟\n"
               );
	
	set("no_sale",1);
	set( "unit", "把" );
 	set( "weapon_class", 23 );
 	set("second",1);
    set("type","shortblade");
	set( "min_damage", 16 );
	set( "max_damage", 25 );
	set( "weight", 71 );
	set( "value", ({ 1800, "silver" }) );
}
