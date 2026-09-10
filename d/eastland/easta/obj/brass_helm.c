#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "brass helm", "銅盔帽" );
	add( "id", ({ "helm" }) );
	set_short( "銅盔帽" );
	set_long("這是一個圓頂的銅製盔帽。\n");
	set( "unit", "頂" );
	set( "type", "head" );
	set( "material", "heavy_metal" );
	set( "weight", 60 );
	set( "armor_class", 4 );
	set( "value", ({ 340, "silver" }) );
}
