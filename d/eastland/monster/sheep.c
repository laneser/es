#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "white sheep", "白綿羊" );
	add( "id", ({ "sheep" }) );
	set_short( "白綿羊" );
	set_long(
		"你看到一隻溫馴的白綿羊，靜靜地在草地上吃草。\n"
	);
	set( "unit", "只" );
	set( "alignment", 500 );
	set_perm_stat("kar", 5 );
	set_c_verbs( ({ "%s用後腿往%s一踢" }) );
	set_c_limbs( ({ "頭部", "身體", "腿部" }) );
}

int stop_attack()
{
	object girl;

	girl = present("shepherdess", environment());
	if( !girl ) return 0;
	girl->protect_sheep(this_object(), this_player());
	return 0;
}
