#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic amulet", "惡魔護身符");
        add( "id", ({ "amulet" }) );
        set_short( "惡魔護身符" );
        set_long(
                "這是古惡魔戰士專用的護身符\n"
        );
        set( "unit", "個");
        set( "type", "misc" );
        set( "material", "heavy_metal");
        set( "armor_class", 0);
        set( "defense_bonus", 5 );
        set( "special_defense",
             ([ "evil":5, "divine":-7 ]) );
        set( "weight", 30 );
        set( "value", ({ 470, "silver" }) );
}
