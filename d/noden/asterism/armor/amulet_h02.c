#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Bronze amulet", "青銅護身符");
        add( "id", ({ "amulet" }) );
        set_short( "青銅護身符");
        set_long(
                " 一個青銅護身符,重量很輕但是似乎能提供很好的保護力\n"
        );
        set("unit","個");
        set( "type", "misc" );
        set("material","light_metal") ;
        set( "armor_class", 0 );
        set( "defense_bonus", 7 );
        set( "weight", 5 );
        set("no_sale",1) ;
        set( "value", ({ 60, "gold" }) );
}



