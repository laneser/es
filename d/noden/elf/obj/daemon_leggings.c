#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic leggings", "惡魔脛甲");
        add( "id", ({ "leggings" }) );
        set_short( "惡魔脛甲" );
        set_long(
                "這是古惡魔戰士專用的脛甲\n"
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "material", "heavy_metal");
        set( "armor_class", 7 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "evil":4, "divine":-3, "cold":-2 ]) );
                       
        set( "weight", 100 );
        set( "value", ({ 200, "gold" }) );
}
