#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white suit", "白色詩人服" );
	add( "id", ({ "suit" }) );
	set_short( "白色詩人服" );
	set_long(
		"這件衣服是用上等的布料製成的，看起來很漂亮也很昂貴。\n"
	);
	set( "unit", "件" );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 2);
	set( "special_defense", ([ "magic":2, "fire":-3 ]) );
	set( "weight", 60 );
	set( "value", ({ 76, "gold" }) );
}
