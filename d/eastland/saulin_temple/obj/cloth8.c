#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "short cloth", "破短掛" );
	add("id",({"cloth"}) ); 
          set_short( "破短掛" );
	set_long(
"這是一件一般遊方和尚穿的衣服，謂之短掛，它有點破了。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "armor_class", 10 );
        set("material","cloth");
	set( "defense_bonus", 2 );
	set( "weight", 50 );
	set( "value", ({ 290, "silver" }) );
}
