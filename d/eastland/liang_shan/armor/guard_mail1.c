#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("Soft mail","軟蝦背心");
    add("id",({"plate","mail"}) );
    set_short( "soft mail","軟蝦背心");
	set_long(
		"\n",
		"這件戰甲由柔軟的蝦殼製成，柔韌的表皮應能發揮以柔克剛的效果．\n"
	);
	set( "unit", "件" );
	set( "weight", 140 );
	set( "type", "body" );
	set( "armor_class", 31 );
        set("material","element");
	set( "defense_bonus", 3 );
	set( "value", ({ 77, "gold" }) );
                                    
}
