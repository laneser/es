#include "../moyada.h"
#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("ant knight", "騎士蟻");
	add( "id", ({ "ant" }) );
	set_short("騎士蟻");
	set_long(
		"騎士蟻是比兵蟻更具戰力的巨蟻，光看那兩片巨大的牙齒就令你心寒。\n"
	);
	set( "max_hp",250);
	set( "hit_points",250);
	set( "unit", "只" );
   set( "race", "insect" );
	set( "alignment", 200 );
	set_natural_weapon( 26, 11, 22 );
	set_natural_armor( 49, 20 );
	set_perm_stat("str",24);
	set_perm_stat("dex",21);
	set_perm_stat("con",24);
	set( "weight", 100);
	set( "c_death_msg", "%s尖叫一聲，抖了幾下不動了 ....\n" );
	set_c_limbs( ({ "頭部", "身體", "腳" }) );
	set_c_verbs( ({ "%s狠狠的往%s咬下去" }) );
	set( "alt_corpse", MOYADA"obj/ant_corpse1" );
}
