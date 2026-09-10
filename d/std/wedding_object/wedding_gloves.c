#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("silk wedding gloves", "白色純絲新娘手套");
        add( "id", ({"gloves" }) );
        set_short("a silk wedding gloves", "白色純絲新娘手套");
        set_long(
                "A wedding gloves made of silk.\n",
                "一雙天然純絲織成的白色新娘手套。\n"
        );
        set( "unit", "雙");
        set( "type", "hands" );
        set("material","cloth");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
	set("no_sale",1);
        set( "value", ({ 1250, "silver" }) );
}
