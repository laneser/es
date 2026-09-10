#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "mithril saddle", "米蘇里馬鞍" );
	add( "id", ({ "saddle" }) );
	set_short(  "米蘇里馬鞍" );
	set_long(
		"這是一副米蘇里制馬鞍，騎士們都會為自己的愛馬選擇舒適的馬鞍。\n" 
		);
	set( "type", "saddle" );
	set( "material", "light_metal" );
	set( "armor_class", 5 );
	set( "weight", 110 );
	set( "value", ({ 430, "silver" }) );
}
