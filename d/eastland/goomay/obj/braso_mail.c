#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel braso mail", "鋼胸甲" );
	add( "id", ({ "scale", "mail" }) );
	set_short( "an steel braso mail", "鋼胸甲" );
	set_long(
		"You see a braso mail covered with many steel scales.\n",
		"這是一件鑲著許多鋼片的胸甲。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
        set("material","heavy_metal");
	set( "weight", 180 );
	set( "armor_class", 20 );
	set( "value", ({ 350, "silver" }) );
}
