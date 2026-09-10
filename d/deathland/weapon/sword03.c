#include "../echobomber.h"

inherit WEAPON;

void create()
{
        set_name("Longsword of Nightmare","惡夢長劍");
        add("id",({"sword","longsword","nightmare"}) );
        set_short("惡夢長劍");
      	set_long(
           "一把會讓你的敵人產生惡夢的鋒利長劍\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
    set("type","longblade");
	set( "min_damage", 18 );
	set( "max_damage", 33 );
	set( "weight", 100 );
	set( "value", ({ 320, "gold" }) );

}

