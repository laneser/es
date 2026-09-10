#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic helmet", "惡魔盔");
        add( "id", ({ "helmet" }) );
        set_short( "惡魔盔" );
        set_long(
                "這是惡魔戰士的專用頭盔 \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "heavy_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "evil":3, "divine":-3, "mental":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 350, "gold" }) );
}


