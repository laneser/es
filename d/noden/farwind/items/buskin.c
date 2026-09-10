#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "buskins", "短統靴" );
	set_short( "短統靴" );
	set_long(
		"這雙短統靴有著厚厚的底部，適合長途跋涉的人穿著。\n"
	);
	set( "unit", "雙" );
	set( "type", "feet" );
	set( "material", "leather");
	set( "armor_class", 4 );
	set( "weight", 40 );
	set( "value", ({ 160, "silver" }) );
}
