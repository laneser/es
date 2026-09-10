#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "thin blade", "柳葉刀" );
	add( "id", ({ "blade" }) );
   set_short( "柳葉刀" );
	set_long(
		"這是一種劍刃彎曲如柳葉的短劍，使用起來輕便靈活。\n"
	);
	set( "unit", "把" );
	set( "weight", 60 );
	setup_weapon( "shortblade", 17, 6, 14 );
	set( "bleeding", 5 );
	set( "value", ({ 44, "gold" }) );
}
