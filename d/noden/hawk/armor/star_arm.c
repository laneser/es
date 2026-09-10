#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Star Armband","流星臂環" );
        add( "id", ({ "armband" }) );
        set_short( "流星臂環" );
        set_long(
                "一對由青玉製成的臂環，上面刻著淡淡的流星雨。\n"
        );
        set( "unit", "對" );
	set("material","element");
        set( "type", "arms" );
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
	set( "extra_skills", (["tactic" : 5, "riding" : 5]) );
        set( "weight", 30 );
        set( "value", ({ 1300, "silver" }) );
}
