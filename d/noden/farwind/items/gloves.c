#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather gloves", "皮手套" );
	add( "id", ({ "gloves" }) );
	set_short( "皮手套" );
	set_long(@CLONG
這雙皮手套是用一種深褐色的皮革製成的，不但保暖，兼可以
保護手部。
CLONG
	);
	set( "unit", "雙" );
	set( "type", "hands" );
	set( "material", "leather" );
	set( "armor_class", 1 );
	set( "weight", 30 );
	set( "value", ({ 110, "silver" }) );
}
