#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "daoist's robe", "八卦袍" );
	add( "id", ({ "robe" }) );
	set_short( "a daoist's robe", "八卦袍" );
	set_long(
		"You see a daoist's robe.\n",
		"這是一件道士常穿的青色長袍，前後各繡了一個八卦圖案。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
        set("material","cloth");
	set( "weight", 100 );
	set( "armor_class", 15 );
	set( "value", ({ 100, "silver" }) );
}
