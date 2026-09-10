#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("general hood", "一字巾");
        add( "id", ({ "hood","general" }) );
        set_short( "a general hood", "一字巾");
        set_long(
                "A general hood .\n",
                "這是一頂普通頭巾，似乎沒什麼防護力... \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 4 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 83, "gold" }) );
}



