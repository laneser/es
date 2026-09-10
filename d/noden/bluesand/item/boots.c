#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "long boots", "長靴" );
	add( "id", ({ "boots" }) );
   set_short( "長靴" );
	set_long( 
		"一雙用海豹皮做成的長統靴，看起來品質不錯。\n"
	);
	set( "unit", "雙" );
	set( "type", "feet" );
    set( "material", "leather");
	set( "armor_class", 6 );
	set( "special_defense",(["cold":3,]) );
	set( "value", ({ 320, "silver" }) );
	set( "weight", 50 );
}
