#include "takeda.h"

inherit WEAPON;

void create()
{
       set_name("death sword","喪門劍");
       add("id",({"sword"}) );
       set_short("喪門劍");
	   set_long(
           "這是一把鋒利的寶劍，可以輕易的奪去敵人生命，故名喪門．\n"
	);
	
	set( "unit", "把" );
 	set( "weapon_class", 26 );
        set("type","longblade");
	set( "min_damage", 18 );
	set( "max_damage", 29 );
	set( "weight", 100 );
	set( "value", ({ 81, "gold" }) );
	
}	
