#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Obsidian boots", "黑曜石長靴");
        add( "id", ({ "boots" }) );
        set_short( "黑曜石長靴");
        set_long(
                "這是一雙黑曜石長靴.\n"
        );
        set("unit","雙");
        set( "type", "feet" );
        set("material","element") ;
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "weight", 130 );
        set( "value", ({ 70, "gold" }) );
}






