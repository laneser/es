#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Dwarven elder cape", "矮人披風");
        add( "id", ({ "cape" }) );
        set_short( "矮人披風");
        set_long(
                "這是矮人族專用的披風，他所代表的是社會地位。 \n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set("material","cloth") ;
        set( "armor_class", 7 );
        set( "defense_bonus", 0 );
        set( "weight", 70 );
        set( "value", ({ 155, "gold" }) );
}



