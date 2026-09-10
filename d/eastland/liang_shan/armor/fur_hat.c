#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("fur hat", "深簷暖帽");
        add( "id", ({ "hat" }) );
        set_short( "fur hat", "深簷暖帽");
        set_long(
                "A fur hat that can make you feel warm .\n",
                "一頂毛絨絨的大帽子，戴起來十分保暖． \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "special_defense",
               ([ "cold":4, "fire":-3]) );
        set( "weight", 40 );
        set( "value", ({ 66, "gold" }) );
}



