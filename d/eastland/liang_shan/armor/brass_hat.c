#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("brass dauist hat", "黃銅道冠");
        add( "id", ({ "hat" }) );
        set_short( "brass dauist hat", "黃銅道冠");
        set_long(
                "A brass hat 6used by dauists .\n",
                "每個道士頭上都有的裝飾物，但不知有沒有防禦功能． \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "light_metal");
        set( "armor_class", 4 );
        set( "defense_bonus", 1 );
        set( "special_defense",
               ([ "evil":5, "divine":-4, "mental":5 ]) );
        set( "weight", 60 );
        set( "value", ({ 22, "gold" }) );
}



