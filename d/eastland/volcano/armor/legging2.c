#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("dark leggings", "黑暗脛甲");
        add( "id", ({ "leggings" }) );
        set_short( "黑暗脛甲");
        set_long(
                "這件脛甲乃是經過地獄之黑暗深淵中煉製而成。\n"
        );
        set("unit","件");
        set( "type", "legs" );
        set( "material", "light_metal");
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "evil":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 200, "gold" }) );
}






