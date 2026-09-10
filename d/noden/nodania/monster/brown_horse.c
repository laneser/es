#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	object saddle;

	::create();
	set_level(6);
	set_name( "brown horse", "棕色馬" );
	add( "id", ({ "horse" }) );
	set_short( "棕色馬" );
	set_long(
		"這是一匹高大、強壯的棕色馬。\n" );
	set( "unit", "匹" );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 2 );
	set( "natural_armor_class", 25 );
	set( "natural_weapon_class1", 8 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 10 );
	set( "alignment", 100 );
	set( "max_load", 1900 );
	set_c_limbs( ({ "頭部", "身體", "後腿", "尾巴" }) );
	set_c_verbs( ({ "%s抬起後腿，往%s一踢", "%s人立起來，用前肢在%s一陣上亂蹬" }) );

	saddle = new( "/d/noden/nodania/obj/leather_saddle" );
	saddle->move( this_object() );
	equip_armor( saddle );
}

void init()
{
//	monster::init();
	mount::init();
}
