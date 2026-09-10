#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("halfling magician cape", "半身人魔法師披風");
        add( "id", ({ "cape" }) );
        set_short( "半身人魔法師披風");
        set_long(
                "這是半身人魔法師專用的披風 \n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set("material","cloth") ;
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "weight", 70 );
        set( "value", ({ 155, "gold" }) );
}



