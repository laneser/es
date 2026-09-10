#include "../oldcat.h"

inherit WEAPON;

void create()
{
       set_name("long spear of Black","黑長矛");
       add("id",({"spear"}) );
       set_short("黑長矛");
       set_long(
           "一把通體烏黑的鋼長矛，可以無聲無息的刺入敵人的心臟。\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 40 );
        set( "type","thrusting");
	set( "min_damage", 20 );
	set( "max_damage", 40 );
	set( "weight", 120 );
	set( "value", ({ 200, "gold" }) );
}
