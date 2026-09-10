#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel helmet", "鋼頭盔" );
	add( "id", ({ "helmet" }) );
	set_short( "鋼頭盔" );
	set_long(
		"這是一個鋼製的頭盔，上面還有保護臉部的鐵面罩。\n"
	);
	set( "unit", "個" );
	set( "type", "head" );
	set( "material", "heavy_metal" );
	set( "armor_class", 8 );
	set( "weight", 60 );
	set( "value", ({ 1520, "silver" }) );
}
