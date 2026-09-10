#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic boots", "惡魔鞋");
        add( "id", ({ "boots" }) );
        set_short( "惡魔鞋" );
        set_long(
                "這是古惡魔戰士專用的戰靴\n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material", "heavy_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "evil":4, "divine":-8, "acid":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 440, "silver" }) );
}
