#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "white bracers", "白雲石手釧" );
	add( "id", ({ "bracers" }) );
	set_short( "白雲石手釧" );
	set_long(
		"這是一對用某種不知名的白石頭造出的手環，看起來相當重。\n"
	);
	set( "unit", "雙" );
	set( "type", "hands" );
	set( "armor_class", 5 );
        set("material","stone");
	set( "weight", 70 );
	set( "value", ({ 1000, "silver" }) );
}
