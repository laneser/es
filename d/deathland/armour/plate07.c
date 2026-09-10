#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("holy plate","聖鎧甲");
        add("id",({"plate","platemail"}) );
         set_short( "a holy plate","聖鎧甲");
	set_long(
         "This plate seems heavy and enhanced with holy power.\n",
         "這是一副厚重的鎧甲,似乎有著神聖的力量附在其中\n"
	         );
	set( "unit", "件" );
	set( "weight", 360 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 30 );
	set( "defense_bonus", 5 );
	set( "special_defense", ([ "divine":10, "evil" :-5, "magic":-10 ]) );
	set( "value", ({ 300, "gold" }) );
}
