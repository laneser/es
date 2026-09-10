#include <mudlib.h>

inherit POTION;

void create()
{
	potion::create();
	set_name( "green potion", "翠綠藥水" );
	add( "id", ({ "potion", "green" }) );
	set_short( "翠綠藥水" );
	set_long( @LONG
這是愛卡拉維亞鎮上老鍊金術師精心提煉的密藥, 擁有絕佳的治療效果。
LONG
	);
	set_healing( 95 );
	set( "no_sale", 1 );
	set( "unit", "瓶" );
	set( "weight", 15 );
	set( "value", ({ 750, "silver" }) );
	set( "medication", 70 );
	set( "effect_critical", 80 );
}
