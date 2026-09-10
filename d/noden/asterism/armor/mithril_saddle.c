#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "mithril saddle", "米蘇里馬鞍" );
	add( "id", ({ "saddle" }) );
	set_short( "米蘇里馬鞍" );
	set_long(
		"這是一副用軟米蘇里金屬製成的馬鞍。能提供較舒適的騎乘感覺。\n" );
	set( "type", "saddle" );
        set("material","light_metal");
	set( "armor_class", 10 );
	set( "defense_bouns",2 );
	set( "weight", 120 );
	set( "value", ({ 950, "silver" }) );
}
