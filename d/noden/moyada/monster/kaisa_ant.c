#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name("Kaisa ant", "凱薩之蟻");
	add( "id", ({ "ant" }) );
	set_short("凱薩之蟻");
	set_long(
		"十分巨大的螞蟻，兩片牙齒就像鐮刀一樣鋒利。\n"
	);
	set( "max_hp",500);
	set( "hit_points",500);
	set( "unit", "只" );
   set( "race", "insect" );
	set( "alignment", 700 );
	set_natural_weapon( 40, 20, 35 );
	set_natural_armor( 80, 35 );
	set_perm_stat("str",28);
	set_perm_stat("dex",20);
	set_perm_stat("con",30);
	set( "weight", 100);
	set( "c_death_msg", "%s尖叫一聲，抖了幾下不動了 ....\n" );
	set_c_limbs( ({ "頭部", "身體", "腳" }) );
	set_c_verbs( ({ "%s狠狠的往%s咬下去" }) );
	set( "alt_corpse", MOYADA"obj/ant_corpse1" );
	set( "exp_reward", 8500 );
}
