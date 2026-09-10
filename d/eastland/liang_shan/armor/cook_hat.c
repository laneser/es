#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("cook hat", "廚師帽");
        add( "id", ({ "hat" }) );
        set_short( "cook hat", "廚師帽");
        set_long(
                "A hat .\n",
                "這是一頂廚師專用的帽子，其上沾滿油垢\n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "fire":4,"mental":1 ]) );
        set( "weight", 60 );
        set( "value", ({ 12, "gold" }) );
}



