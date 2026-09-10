#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("Chinese halbert","方天畫戟");
       add("id",({"halbert"}) );
       set_short("方天畫戟");
	   set_long(
           "戟是組合槍和長刀而成的武器，兼有兩者的優點，方天畫戟是其中\n"
	   "較有威力的一種．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 26 );
    set("type","polearm");
	set( "min_damage", 16 );
	set( "max_damage", 30 );
	set( "nosecond",1);
	set( "weight", 130 );
	set( "value", ({ 90, "gold" }) );
	
}	
