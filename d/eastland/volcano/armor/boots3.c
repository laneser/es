#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("cloud boots", "步雲靴");
        add( "id", ({ "boots" }) );
        set_short( "步雲靴");
        set_long(
                "這雙靴子乃是神仙們常穿的鞋，據說可以踏雲而行。\n"
        );
        set("unit","雙");
        set( "type", "feet" );
        set( "material", "element");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "cold":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 280, "gold" }) );
}






