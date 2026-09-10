#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "perichy", "裴瑞琪" );
	add( "id", ({ "artist", "court artist" }) );
	set_short( "宮廷畫家裴瑞琪" );
	set_long(@CLONG
裴瑞琪是諾達尼亞王宮中最年輕的宮廷畫師，她正在計畫這幾個月要到
東方去旅行。
CLONG
	);
	set( "race", "daemon" );
	set( "gender", "female" );
	set( "natural_weapon_class1", 24 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 15 );
	set( "alignment", 600 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 70 );
	set_skill( "longblade", 70 );
	set( "exp_reward", 2200 );
}
