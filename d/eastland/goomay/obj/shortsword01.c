#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel shortsword", "精鋼短劍" );
	add( "id", ({ "shortsword", "sword" }) );
	set_short( "a highsteel shortsword", "精鋼短劍" );
	set_long(
		"You see an excellent shortsword made of highsteel.\n",
		"這是一把千錘百煉，純鋼鍛成的短劍，是本鎮劍廬的精品。\n"
	);
	set( "unit", "把" );
	set( "weight", 90 );
	setup_weapon( "shortblade", 25, 11, 22 );
//	set( "bleeding", 5 );
	set( "value", ({ 420, "silver" }) );
}
