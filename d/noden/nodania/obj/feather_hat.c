#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "feathered hat", "羽飾帽" );
	add( "id", ({ "hat" }) );
	set_short( "羽飾帽" );
	set_long(
		"這頂帽子的邊邊插了一根白羽毛做裝飾。\n"
	);
	set( "unit", "頂" );
	set( "type", "head" );
	set( "material", "leather");
	set( "armor_class", 3 );
	set( "weight", 30 );
	set( "value", ({ 120, "silver" }) );
}
