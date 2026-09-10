#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("cloud leggings", "流雲脛甲");
        add( "id", ({ "leggings" }) );
        set_short("流雲脛甲");
        set_long(
                "這件脛甲乃是經過長老用強力法術將天空浮雲化成的。\n"
        );
        set("unit","件");
        set( "type", "legs" );
        set( "material", "element");
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "electric":5 ]) );
        set( "weight", 70 );
        set( "value", ({ 250, "gold" }) );
}






