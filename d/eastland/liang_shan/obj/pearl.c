#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "Moon pearl", "夜明珠" );
	add( "id", ({ "pearl" }) );
	set_short( "moon pearl", "夜明珠" );
	set_long(
		".\n",
		"這是一顆罕見的大珍珠，發出夢幻般的光芒，據傳是大蚌精\n"
		"吸收月光精華的結晶。\n"
	);
	set( "unit", "顆" );
	set( "light", 1 );
	set( "weight", 30 );
	set( "value", ({ 3000, "silver" }) );
	set( "no_sale", 1 );
}
