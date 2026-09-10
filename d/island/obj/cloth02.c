#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black suit","黑色勁裝" );
	add( "id", ({ "suit","cloth" }) );
	set_short( "黑色勁裝" );
	set_long(
		"這是錢形次郎早年犯案時慣用的服裝，據說穿來特別身輕如燕。\n"
	);
	set( "unit", "領" );
        set("material","cloth");
	set( "type", "body" );
        set( "armor_class", 40 );
        set( "defense_bonus", 5 );
	set( "weight", 100 );
	set( "value", ({ 1500, "silver" }) );
	set( "extra_stats" ,(["pie" : -1 , "dex" : 1 ]) );
}
