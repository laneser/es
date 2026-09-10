#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "glasses", "墨鏡" );
	set_short( "墨鏡" );
	set_long(
		"這是一付很拉風的墨鏡，可以擋住強光的照射。\n"
	);
	set( "unit", "付" );
        set("material","element");
	set( "type", "head" );
	set( "weight", 20 );
	set( "armor_class", 2 );
	set( "value", ({ 40, "silver" }) );
        set( "extra_look", "$N戴著一付很拉風的墨鏡，顯得十分帥氣。\n" );

}
