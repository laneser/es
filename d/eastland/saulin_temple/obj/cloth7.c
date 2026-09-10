#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "short cloth", "短掛" );
	add("id",({"cloth"}) ); 
          set_short( "短掛" );
	set_long(
"這是一件一般遊方和尚穿的衣服,謂之短掛。\n"
	);
	set( "unit", "件" );
        set("material","cloth");
	set( "type", "body" );
	set( "armor_class", 10 );
	set( "defense_bonus", 3 );
	set( "weight", 70 );
	set( "value", ({ 470, "silver" }) );
}
