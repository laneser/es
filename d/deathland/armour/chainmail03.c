#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("gray chainmail","灰色□甲");
        add("id",({"chainmail"}) );
        set_short( "a gray chainmail","灰色□甲");
	    set_long(
  "這是一副曾經被許多士兵穿過的□甲,過了這麼多年已經變成灰色了\n"
	);
	set( "unit", "件" );
	set( "weight", 230 );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 15 );
	set( "defense_bonus", 0 );
	set( "value", ({ 400, "silver" }) );
}
