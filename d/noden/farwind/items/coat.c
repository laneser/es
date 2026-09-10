#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "dirty coat", "髒外套" );
	add( "id", ({ "coat" }) );
	set_short( "髒外套" );
	set_long(
		"這件外套上滿是汙泥與油漬，還有一股濃濃的酒臭味。\n"
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "cloth");
	set( "armor_class", 1 );
	set( "weight", 40 );
	set( "value", ({ 12, "silver" }) );
}
