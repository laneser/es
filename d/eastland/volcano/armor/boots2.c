#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith boots", "矮靈鞋");
        add( "id", ({ "boots" }) );
        set_short("矮靈鞋");
        set_long(
                "這雙鞋乃是經過祭師科拉克以烈火力量煉製而成。\n"
        );
        set("unit","雙");
        set( "type", "feet" );
        set( "material", "element");
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "fire":5 ]) );
        set( "weight", 90 );
        set( "value", ({ 280, "gold" }) );
}






