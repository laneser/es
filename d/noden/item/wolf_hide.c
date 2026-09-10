#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wolf hide", "狼皮披肩" );
	add( "id", ({ "hide" }) );
   set_short( "狼皮披肩" );
	set_long(
		"這是一個巨人用狼皮做成的披肩，不知道從哪裡獵到這麼大的狼，你可以\n"
		"把它當披風穿。\n"
	);
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "material", "leather");
	set( "armor_class", 7 );
	set( "weight", 140 );
	set( "value", ({ 450, "silver" }) );
}
