#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "waiter", "店小二" );
	set_short( "店小二" );
	set_long(
		"店小二說: 客倌請裡面坐！\n"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set_perm_stat( "dex", 5 );
	set_skill( "dodge", 30 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 8 );
	set( "wealth/copper", 100 );
	set( "chat_chance", 50 );
	set( "att_chat_output", ({
		"店小二說道: 大爺饒命 ....\n",
		"店小二說道: 我這是招誰惹誰了 ....\n",
		"店小二左閃右躲，說道: 拜託拜託，有話好說！\n"
	}) );
}
