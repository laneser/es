#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith amulet", "矮靈護身符");
        add( "id", ({ "amulet" }) );
        set_short("矮靈護身符");
        set_long(
                "這個護身符乃是經過祭師科拉克以強酸力量煉製而成。\n"
        );
        set("unit","個");
        set( "type", "misc" );
        set( "material", "element");
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "acid":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 90, "gold" }) );
}






