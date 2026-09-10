#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("panther_fur pants", "豹皮褲");
        add( "id", ({ "pants" }) );
        set_short("panther_fur pants", "豹皮褲");
        set_long(
                "a pants made of fur of panther .\n",
                "用豹皮製成的緊身褲，伸縮性佳，但不太透氣．\n"
        );
        set( "unit", "件");
        set( "type", "legs" );
        set( "material", "leather");
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "cold":4, "fire":-5 ]) );
                       
        set( "weight", 160 );
        set( "value", ({ 150, "gold" }) );
}
