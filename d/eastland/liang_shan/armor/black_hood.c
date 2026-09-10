#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("black hood", "皂巾");
        add( "id", ({ "hood","black" }) );
        set_short( "a black hood", "皂巾");
        set_long(
                "A black hood .\n",
                "這是一頂破破爛爛的黑頭巾，通常是沒什麼身份地位的人穿的 \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 3 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 10, "gold" }) );
}



