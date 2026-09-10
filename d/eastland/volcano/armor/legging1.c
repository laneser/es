#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith leggings", "矮靈脛甲");
        add( "id", ({ "leggings" }) );
        set_short("矮靈脛甲");
        set_long(
                "這件脛甲乃是經過祭師科拉克以邪惡力量煉製而成。\n"
        );
        set("unit","件");
        set( "type", "legs" );
        set( "material", "element");
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "evil":5 ]) );
        set( "weight", 80 );
        set( "value", ({ 200, "gold" }) );
}






