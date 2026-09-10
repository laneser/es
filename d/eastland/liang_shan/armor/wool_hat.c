#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("wool hat", "白范陽氈大帽");
        add( "id", ({ "hat" }) );
        set_short( "wool hat", "白范陽氈大帽");
        set_long(
                "A white wool hat that can make you feel warm .\n",
                "一頂白色毛絨絨的大帽子，戴起來十分保暖． \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "cold":3, "fire":-3]) );
        set( "weight", 35 );
        set( "value", ({ 56, "gold" }) );
}



