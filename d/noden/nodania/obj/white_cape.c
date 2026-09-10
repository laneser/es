#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white cape", "白披風" );
	add( "id", ({ "cape" }) );
	set_short(  "白色披風" );
	set_long(
		"這件白色披風看起來很漂亮而且昂貴，上面有一個小小的玫瑰標誌。\n"
	);
	set( "unit", "件" );
	set( "weight", 50 );
	set( "type", "cloak" );
	set( "material" ,"cloth" );
	set( "armor_class", 4 );
	set( "defense_bonus", 3 );
	set( "special_defense", ([ "mental":3 ]) );
	set( "value", ({ 136, "gold" }) );
}
