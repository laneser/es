#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith cloak", "矮靈披風");
        add( "id", ({ "cloak" }) );
        set_short( "矮靈披風");
        set_long(
                "這件披風乃是經過祭師科拉克以神聖力量煉製而成。\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "element");
        set( "armor_class", 4 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "divine":5 ]) );
        set( "weight", 90 );
        set( "value", ({ 250, "gold" }) );
}






