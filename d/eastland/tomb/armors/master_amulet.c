#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "master amulet", "天師護符" );
	add( "id", ({ "amulet" }) );
	set_short( "天師護符" );
	set_long(
		"一個漂亮的護符，上面有著一些彎彎曲曲的魔法符號，你看不懂\n"
		"在畫些什麼。\n"
	);
	set( "unit", "面" );
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "defense_bonus", 7 );
	set( "special_defense",
	     ([ "fire":20, "cold":20, "electric":10, "energy":10 ]) );
	set( "no_sale", 1);
	set( "weight", 5 );
	set( "value", ({ 3500, "silver" }) );
}
