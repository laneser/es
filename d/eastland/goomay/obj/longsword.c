#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "highsteel longsword", "長劍" );
	add( "id", ({ "longsword", "sword" }) );
	set_short( "a highsteel longsword", "青鋼長劍" );
	set_long(
		"You see an excellent longsword made of highsteel.\n",
		"這是一把質地堅硬，青鋼鑄成的長劍。\n"
	);
	set( "unit", "把" );
	set( "weight", 90 );
	setup_weapon( "longblade", 22, 9, 20 );
//	set( "bleeding", 5 );
	set( "value", ({ 520, "silver" }) );
}
