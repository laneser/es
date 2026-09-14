#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("green chainmail","點翠團花戰甲");
    add("id",({"chainmail","mail"}) );
    set_short( "green chainmail","點翠團花戰甲");
	set_long(
		"This is a suit of green chainmail \n",
		"這是一件綠油油的鎧甲，不知道是用什麼金屬製成的，胸前有\n"
		"許多美麗的繡花圖案．\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 150 );
	set( "type", "body" );
	set( "armor_class", 34 );
        set("material","heavy_metal");
	set( "defense_bonus", 4 );
	set( "value", ({ 290, "gold" }) );
}
