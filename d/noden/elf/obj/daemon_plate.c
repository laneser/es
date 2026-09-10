#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic platemail", "惡魔鱗甲");
        add( "id", ({ "mail","platemail" }) );
        set_short( "惡魔鱗甲" );
        set_long(
                "這是惡魔戰士所專用的鱗甲。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "heavy_metal");
        set( "armor_class", 28 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "evil":8, "divine":-5, "energy":-2 ]) );
        set( "weight", 280 );
        set( "value", ({ 200, "gold" }) );
}
