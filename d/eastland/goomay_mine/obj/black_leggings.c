#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black leggings", "黑色護膝" );
	add( "id", ({ "leggings" }) );
	set_short( "黑色護膝" );
	set_long(
		"這是一個黑色的的護膝，看不出是用什麼做成的。\n"
	);
	set( "unit", "副" );
	set( "type", "legs" );
	set( "material", "light_metal" );
	set( "armor_class", 8 );
	set( "weight", 50 );
	set( "value", ({ 1320, "silver" }) );
}
