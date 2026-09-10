#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black boots", "黑布靴" );
	add( "id", ({ "boots" }) );
	set_short( "黑布靴" );
	set_long("這是一雙用黑色布縫的厚底長靴。\n");
	set( "unit", "雙" );
	set( "type", "feet" );
	set( "material", "cloth" );
	set( "weight", 30 );
	set( "armor_class", 4 );
	set( "value", ({ 310, "silver" }) );
}
