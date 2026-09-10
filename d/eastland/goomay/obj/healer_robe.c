#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "healer's robe", "醫生診袍" );
	add( "id", ({ "robe" }) );
	set_short( "an healer's robe", "醫生診袍" );
	set_long(
		"You see a healer's robe.\n",
		"這是一件醫生常穿的白色長袍，上面沾了一些斑斑點點的血跡。\n"
	);
	set( "unit", "件" );
        set("material","healer");
	set( "type", "body" );
	set( "weight", 80 );
	set( "armor_class", 20 );
	set( "value", ({ 150, "silver" }) );
}
