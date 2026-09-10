#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name( "golden dragon orb", "金龍珠" );
	add( "id", ({ "key","orb" }) );
	set_short( "金龍珠" );
	set_long(
		"這是一顆金色的珠子，上面流動著奇異的光芒。\n"
	);
	set( "unit", "顆" );
	set( "to_lock", "TOMBKEY_1" );
	set( "weight", 5 );
	set( "value", ({ 10, "copper" }) );
	set( "no_sale", 1 );
}
