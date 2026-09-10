#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "buckler", "圓盾" );
   set_short( "圓盾" );
	set_long(
		"這個圓盾已經相當舊了，上面還被武器砍出幾道缺口，不過看起來仍然\n"
		"相當耐用。\n"
	);
	set( "type", "shield" );
	set( "material", "light_metal" );
	set( "weight", 70 );
	set( "armor_class", 2 );
	set( "defense_bonus", 1 );
	set( "value", ({ 285, "silver" }) );
}
