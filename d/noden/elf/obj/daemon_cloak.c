#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic cloak", "惡魔披風");
        add( "id", ({ "cloak" }) );
        set_short( "惡魔披風" );
        set_long(
                "這是古惡魔戰士所專用的披風 \n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "heavy_metal" );
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "special_defense",
              ([ "evil":3, "divine":-4, "fire":2 ]) );
        set( "weight", 80 );
        set( "value", ({ 530, "silver" }) );
}
