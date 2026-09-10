#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("floral platemail","梅花榆葉甲");
    add("id",({"plate","platemail"}) );
    set_short( "iron platemail","梅花榆葉甲");
	set_long(
		"This is a plate called floral platemail....\n",
		"這是用許多細密的鐵葉所組合成的戰甲，與其說它是防具不如稱它\n"
		"為藝術品，在鐵葉間，點綴著許多梅花型的飾品．\n"
	);
    set( "no_sale",1);
	set( "unit", "件" );
	set( "weight", 170 );
	set( "type", "body" );
	set( "armor_class", 36 );
        set("material","light_metal");
	set( "defense_bonus", 7 );
	set( "value", ({ 253, "gold" }) );
}
