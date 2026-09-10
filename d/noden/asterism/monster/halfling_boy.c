#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "halfling boy", "半身人小男孩" );
	add("id",({"boy","halfling"}) );
   set_short( "半身人小男孩" );
	set_long(
		"你看到帶著笑臉的半身人男孩,他正高高興興地載歌載舞.\n"
	);
	set( "gender", "male" );
	set( "race", "halfling" );
	set( "alignment", 320 );
	set( "time_to_heal", 10 );
	set_natural_armor( 13, 2 );
	set_natural_weapon( 5 , 2 , 3 );
	set_perm_stat( "kar", 10 );
	set( "wealth/silver", 22 );
	wield_weapon(WEAPONS"small_pick");
}

