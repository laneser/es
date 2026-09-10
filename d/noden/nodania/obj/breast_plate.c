#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel breastplate", "鋼胸甲" );
	add( "id", ({ "plate", "breastplate" }) );
	set_short( "鋼胸甲" );
	set_long(
		"一件擦得閃亮耀眼的鋼鑄胸甲。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 28 );
	set( "weight", 280 );
	set( "value", ({ 1970, "silver" }) );
}
