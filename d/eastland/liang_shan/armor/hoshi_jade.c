#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("hoshi jade", "和氏璧");
        add( "id", ({ "jade" }) );
        set_short("和氏璧");
        set_long(
                "這是聞名於世的和氏璧，由上看色如羊脂，側面則如碧玉，下方刻\n"
                "著: 受命於天，既壽且昌．相傳是楚人卞和所發現，故名和氏．\n"
        );
        set( "no_sale",1);
        set( "unit", "塊");
        set( "type", "misc" );
        set( "material", "element");
        set( "armor_class", 0);
        set( "defense_bonus", 8 );
        set( "special_defense",
             ([ "evil":8, "none":-7,"poison":5 ]) );
        set( "weight", 30 );
        set( "value", ({ 1880, "silver" }) );
}
