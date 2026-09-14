#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("gold chainmail","鎖子黃金甲");
    add("id",({"chainmail","mail"}) );
    set_short( "gold chainmail","鎖子黃金甲");
	set_long(
		"This is a suit of chainmail made of gold meterial.\n",
		"這是一件金光閃閃的鎧甲,相傳是當年齊天大聖的裝備之一，雖然它\n"
		"是黃金製成，但不知為何非常的輕巧．\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 130 );
	set( "type", "body" );
	set( "armor_class", 40 );
        set("material","heavy_metal");
	set( "defense_bonus", 5 );
	set( "value", ({ 290, "gold" }) );
}
