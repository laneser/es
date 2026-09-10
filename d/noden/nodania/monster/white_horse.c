#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(11);
	set_name( "white horse", "白色馬" );
	add( "id", ({ "horse" }) );
	set_short( "白色馬" );
	set_long(
		"這是一匹高大、強壯的白色馬，通常以白馬為座騎的騎士地位都不低。\n" );
	set( "unit", "匹" );
	set_perm_stat( "str", 19 );
	set_perm_stat( "int", 7 );
	set( "natural_armor_class", 50 );
	set( "natural_weapon_class1", 19 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 21 );
	set( "alignment", 100 );
	set( "max_load", 2100 );
	set_c_limbs( ({ "頭部", "身體", "後腿", "尾巴" }) );
	set_c_verbs( ({ "%s抬起後腿，往%s一踢", "%s人立起來，用前肢在%s一陣上亂蹬" }) );

	equip_armor("/d/noden/nodania/obj/mithril_saddle" );
}

void init()
{
//	monster::init();
	mount::init();
}
