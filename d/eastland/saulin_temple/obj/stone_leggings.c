#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("stone leggings", "巨石護膝");
        add( "id", ({ "leggings" }) );
        set_short("巨石護膝");
        set_long(
              "這是野蠻人戰士專用的護膝，它非常的重，但可以嚴密的保護你的腳部\n"
        );
        set( "unit", "副");
        set( "type", "legs" );
        set( "material", "stone");
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "fire":4, "cold":-3, "divine":-1 ]) );
                       
        set( "weight", 130 );
        set( "value", ({ 90, "gold" }) );
}
