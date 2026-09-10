#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel platemail", "鋼盔甲" );
	add( "id", ({ "plate", "platemail" }) );
	set_short( "鋼盔甲" );
	set_long(
		"這是一套鋼製的沈重盔甲，不過它雖然重，卻能提供相當好的防禦力。\n"
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 33 );
	set( "weight", 320 );
	set( "value", ({ 2500, "silver" }) );
}
