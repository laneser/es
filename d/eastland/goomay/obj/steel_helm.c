#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel helm", "鋼盔" );
	add( "id", ({ "helm" }) );
	set_short( "a steel helm", "鋼盔" );
	set_long(
		"You see a steel helm with protective hood.\n",
		"這是一個圓頂的鋼製頭盔。\n"
	);
	set( "unit", "頂" );
	set( "type", "head" );
	set("material","heavy_metal");
	set( "weight", 60 );
	set( "armor_class", 5 );
	set( "value", ({ 240, "silver" }) );
}
