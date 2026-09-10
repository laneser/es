#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("Gurad mail","紅蟹甲");
    add("id",({"plate","mail"}) );
    set_short( "guard mail","紅蟹甲");
	set_long(
		"\n",
		"這件戰甲由紅蟹殼製成，堅硬的表皮應能抵擋一般的攻擊．\n"
	);
	set( "unit", "件" );
	set( "weight", 220 );
	set( "type", "body" );
	set( "armor_class", 33 );
        set("material","element");
	set( "defense_bonus", 6 );
	set( "value", ({ 70, "gold" }) );
                                    
}
