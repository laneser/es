#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith armband", "矮靈臂環");
        add( "id", ({ "armband" }) );
        set_short("矮靈臂環");
        set_long(
                "這個臂環乃是經過祭師科拉克以冰雪力量煉製而成。\n"
        );
        set("unit","個");
        set( "type", "arms" );
        set( "material", "element");
        set( "armor_class", 4 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "cold":5 ]) );
        set( "weight", 100 );
        set( "value", ({ 100, "gold" }) );
}






