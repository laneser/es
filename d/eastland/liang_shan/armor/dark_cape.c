#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("black robe","黑絲綢法衣");
    add("id",({"robe","cloth"}) );
    set_short( "black robe","黑絲綢法衣");
	set_long(
		"This is a anti-magic black robe.\n",
		"這是一件泛著黑氣的奇怪法衣，似乎可以吸收附近的光線和能量．\n"
		"光是看著它就覺得不太舒服，若穿上它不知會如何?\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 70 );
	set( "type", "body" );
	set( "armor_class", 22 );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "value", ({ 290, "gold" }) );
        set( "special_defense",(["magic":10,"energy":10,"electric":10,"fire":15,"cold":15]));
        set( "extra_stats",(["con":-1,"str":-2,"kar":-1]));
}
