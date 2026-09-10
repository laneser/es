#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name( "wedding pants", "長褲");
        add( "id", ({ "pants" }) );
        set_short( "a pair of pants", "新郎禮服的長褲");
        set_long(
                "A pair of wedding pants made of silk.\n",
                "這是一件由天山蠶絲織成的長褲。\n"
        );
        set( "unit", "條");
        set( "type", "legs" );
        set( "material","cloth" ) ;
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
        set( "no_sale", 1 );
        set( "value", ({ 60, "gold" }) );
}
