#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("iron helmet", "鋪霜耀日鑌鐵盔");
        add( "id", ({ "helmet" }) );
        set_short( "iron helmet", "鋪霜耀日鑌鐵盔");
        set_long(
                "A iron helmet .\n",
                "這是用鑌鐵鑄成的盔，冷冷的金屬光澤泛起一股寒意． \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "heavy_metal");
        set( "armor_class", 9 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "fire":5, "cold":-2, ]) );
        set( "weight", 80 );
        set( "value", ({ 280, "gold" }) );
}



