#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("holy helmet", "神聖頭盔");
        add( "id", ({ "helmet" }) );
        set_short( "a holy helmet", "神聖頭盔");
        set_long(
                "A huge helmet enchanted holy power.\n",
                "這是一頂附加神聖力的頭盔. \n"
                
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 7 );
        set( "defense_bonus", 4 );
        set( "special_defense", ([ "divine":10 ,"none":-5 ]) );
        set( "weight", 100 );
        set( "value", ({ 2000, "silver" }) );
}



