#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "hankra ball", "漢卡拉之球" );
	add( "id", ({ "ball" }) );
   set_short( "漢卡拉之球" );
	set_long(
		"漢卡拉之球正發出一團柔和的光芒，傳說中這種光芒是永恆的、智慧的\n"
		"思想與遠古的存在。\n"
	);
	set( "unit", "顆" );
	set( "light", 1 );
	set( "weight", 70 );
	set( "value", ({ 300, "silver" }) );
	set( "no_sale", 1 );
}
