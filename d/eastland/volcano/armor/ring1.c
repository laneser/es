#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith ring", "矮靈戒指");
        add( "id", ({ "ring" }) );
        set_short( "矮靈戒指");
        set_long(
                "這隻戒指乃是經過祭師科拉克以劇毒力量煉製而成。\n"
        );
        set("unit","只");
        set( "type", "finger" );
        set( "material", "element");
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "poison":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 120, "gold" }) );
}






