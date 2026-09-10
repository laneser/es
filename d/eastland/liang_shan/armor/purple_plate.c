#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("purple platemail","紫繡團胸戰甲");
    add("id",({"plate","platemail"}) );
    set_short( "purple platemail","紫繡團胸戰甲");
	set_long(
		"This is a platemail with beautiful marks....\n",
		"這是一件美麗的戰甲，胸前繡滿了美麗的圖案，令人心曠神怡，你覺\n"
		"得擁有它的人必定是個很有品味的人．\n"
	);
	set( "unit", "件" );
	set( "weight", 130 );
	set( "type", "body" );
	set( "armor_class", 25 );
        set("material","heavy_metal");
	set( "defense_bonus", 7 );
	set( "value", ({ 153, "gold" }) );
}
