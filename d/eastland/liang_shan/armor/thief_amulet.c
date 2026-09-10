#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("twilight amulet", "黎明護身符");
        add( "id", ({ "amulet" }) );
        set_short("twilight amulet", "黎明護身符");
        set_long(
                "這是一個保護夜行人不受毒蟲及邪魅侵害的護身符\n"
        );
        set( "unit", "個");
        set( "type", "misc" );
        set( "material", "cloth");
        set( "armor_class", 0);
        set( "defense_bonus", 5 );
        set( "special_defense",
             ([ "evil":10, "poison":10 ]) );
        set( "weight", 30 );
        set( "value", ({ 570, "silver" }) );
}
