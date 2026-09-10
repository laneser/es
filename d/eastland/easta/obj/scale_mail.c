#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "scale mail", "鐵鱗甲" );
	add( "id", ({ "scale", "mail" }) );
	set_short( "鐵鱗甲" );
	set_long("這是一件鑲著許多鐵片的鱗甲。\n");
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "weight", 180 );
	set( "armor_class", 18 );
	set( "value", ({ 720, "silver" }) );
}
