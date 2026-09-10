#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("black cloth","皂直綴");
    add("id",({"cloth"}) );
    set_short( "black cloth","皂直綴");
	set_long(
		"This is a black cloth \n",
		"這是一件式樣簡單的黑衣，通常是做小生意的人在穿．\n"
		
	);
	set( "unit", "件" );
	set( "weight", 60 );
	set( "type", "body" );
	set( "armor_class", 15 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "value", ({ 33, "gold" }) );
}
