#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("iron platemail","鐵葉鎧甲");
    add("id",({"plate","platemail"}) );
    set_short( "iron platemail","鐵葉鎧甲");
	set_long(
		"This is a plate called iron platemail....\n",
		"這是用許多細密的鐵葉所組合成的戰甲，與其說它是防具不如稱它\n"
		"為藝術品，穿上它你整個人感覺奐然一新\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 170 );
	set( "type", "body" );
	set( "armor_class", 35 );
        set("material","heavy_metal");
	set( "defense_bonus", 6 );
	set( "value", ({ 251, "gold" }) );
}
