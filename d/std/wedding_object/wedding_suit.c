#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wedding suit","白色新娘禮服");
        add("id",({"suit"}) );
         set_short( "a wedding suit","白色新娘禮服");
	set_long(
"This is a suit of wedding suit made of true white silk meterial.\n",
"這是一件白色的新娘禮服，純白的顏色代表純潔無暇的愛情。\n"
	);
	set( "unit", "件" );
	set("material","cloth");
	set( "weight", 150 );
	set( "type", "body" );
	set( "armor_class", 28 );
	set( "defense_bonus", 5 );
	set("no_sale",1);
	set( "value", ({ 318, "gold" }) );
}
