#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("golden ring","太原府紐絲金環");
        add("id",({"ring"}) );
         set_short( "golden ring","太原府紐絲金環");
	set_long(
"This is a golden ring . \n"
"這是太原府的特產，東方大陸的遊客到太原府一定會買一個來戴戴\n"
);
	set( "unit", "個" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material","adventurer");
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
	set( "value", ({ 150, "gold" }) );
        set( "extra_skills",(["whip":10]));
}
