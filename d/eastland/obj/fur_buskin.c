#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fur buskin", "獸皮短靴" );
	add( "id", ({ "buskin", "buskins" }) );
   set_short( "獸皮短靴" );
	set_long(
		"這是一雙骯髒的獸皮短靴，上面用皮繩纏了好幾圈。\n"
	);
	set( "unit", "雙" );
	set( "type", "feet" );
	set( "material", "leather" );
	set( "weight", 40 );
	set( "armor_class", 2 );
	set( "defense_bonus", 1 );
	set( "special_defense", ([ "fire":-3, "cold":1 ]) );
	set( "value", ({ 260, "silver" }) );
}
