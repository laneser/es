#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "regular chainmail", "□甲" );
	add( "id", ({ "chain", "mail", "regular" }) );
	set_short( "制式□甲" );
	set_long(
		"這件□甲看起來很重，但是相對地能提供相當不錯的保護。\n"
	);
	set( "unit", "件" );
	set( "weight", 180 );
	set( "type", "body" );
	set( "material" ,"heavy_metal" );
	set( "armor_class", 15 );
	set( "value", ({ 400, "silver" }) );
}
