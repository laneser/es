#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "skull glaive", "鬼頭刀" );
	add( "id", ({ "glaive" }) );
   set_short( "鬼頭刀" );
	set_long(
		"這是一把沈重的大刀，刀柄上刻著一個兇惡猙獰的鬼頭。\n"
	);
	set( "unit", "把" );
	set( "weight", 150 );
	setup_weapon( "longblade", 26, 11, 29 );
	set( "bleeding", 5 );
	set( "value", ({ 72, "gold" }) );
}
