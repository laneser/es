#include "../ekravia.h"
inherit ARMOR;

void	create()
{
	set_name("chainmail", "鎧甲");
	add( "id", ({ "mail","chainmail" }) );
	set_short( "鎧甲" );
	set_long(
		"一件金屬製成的鎧甲。\n"
	);
	set("unit","件");
	set( "type", "body" );
	set( "material", "light_metal" );
	set( "armor_class", 15 );
	set( "defense_bonus", 2 );
	set( "weight", 150 );
	set( "value", ({ 600, "silver" }) );
}






