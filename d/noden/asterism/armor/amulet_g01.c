#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("small gold amulet", "黃金鎖片");
        add( "id", ({ "amulet" }) );
        set_short( "黃金鎖片");
        set_long(
                " 一個地精用來為孩子祈壽延命之用的黃金鎖片。\n"
        );
        set("unit","個");
        set( "type", "misc" );
        set("material", "light_metal") ;
        set( "armor_class", 0 );
        set( "defense_bonus", 2 );
        set( "weight", 5 );
        set( "value", ({ 5, "gold" }) );
}



