#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "sandals", "涼鞋" );
	add( "id", ({ "sandal" }) );
   set_short( "涼鞋" );
	set_long(
		"一雙看起來頗為舒適的涼鞋。\n"
	);
	set( "unit", "雙" );
	set( "type", "feet" );
	set( "material", "leather");
	set( "armor_class", 1 );
	set( "weight", 15 );
	set( "value", ({ 26, "silver" }) );
}
