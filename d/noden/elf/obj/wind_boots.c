#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("fur boots", "獸皮靴子");
        add( "id", ({ "boots" }) );
        set_short( "獸皮靴子" );
        set_long(
                "這是精靈用獸皮所烘製成的靴子 \n"
        );
        set( "unit","雙");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "mental":1, "evil":-1 ]) );
        set( "weight", 50 );
        set( "value", ({ 250, "silver" }) );
}
