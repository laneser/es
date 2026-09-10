#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(10);
	set_name( "red horse", "紅鬃烈馬" );
	add( "id", ({ "horse" }) );
	set_short( "紅鬃烈馬" );
	set_long(
		"一隻紅色的小馬，但它的脾氣似乎不太好。\n" );
	set( "unit", "只" );
	set_perm_stat( "str", 10 );
	set_perm_stat( "dex", 15 );
	set( "natural_armor_class", 25 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 20 );
	set( "alignment", 10 );
	set( "max_load", 2000 );
	set_limbs( ({ "head", "body", "feet", "tail" }) );
	set_c_limbs( ({ "頭部", "身體", "後腿", "尾巴" }) );
	set_verbs( ({ "kick" }) );
	set_c_verbs( ({  "%s撲動前蹄，向前直擊%s", "%s紅尾巴一甩，一團紅雲掃向%s" }) );

}

void init()
{
	mount::init();
}
