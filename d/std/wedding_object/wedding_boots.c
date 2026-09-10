#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding boots", "白色新娘鞋");
        add( "id", ({ "boots" }) );
        set_short("a pair of wedding boots", "白色新娘鞋");
        set_long(
                "A pair of boots made for wedding.\n",
		 "這是一雙由純絲製成的白色新娘鞋，看起來十分高雅大方。\n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set("material","cloth");
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
	set("no_sale",1);
        set( "weight", 100 );
        set( "value", ({ 2450, "silver" }) );
}
