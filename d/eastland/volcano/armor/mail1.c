#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith mail", "矮靈護甲");
        add( "id", ({ "mail" }) );
        set_short( "矮靈護甲");
        set_long(
                "這件護甲乃是經過祭師科拉克以精神力量煉製而成。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "element");
        set( "armor_class", 27 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "mental":5 ]) );
        set( "weight", 250 );
        set( "no_sell",1);
        set( "value", ({ 400, "gold" }) );
}






