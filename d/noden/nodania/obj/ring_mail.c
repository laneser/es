#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "ring mail", "環甲" );
	add( "id", ({ "mail", "ring" }) );
	set_short( "環甲" );
	set_long(
		"這是一件環甲，用成千上萬個金屬環接合而成。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 10 );
	set( "weight", 110 );
	set( "value", ({ 140, "silver" }) );
}
