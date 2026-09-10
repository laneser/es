#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding boots", "尖頭皮鞋");
        add( "id", ({ "boots" }) );
        set_short("a pair of wedding boots", "尖頭皮鞋");
        set_long(
                "A pair of boots made for wedding.\n",
                "一雙黑的發亮的尖頭皮鞋。\n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material" , "leather" ) ; 
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "no_sale", 1 );
        set( "weight", 100 );
        set( "value", ({ 2450, "silver" }) );
}
