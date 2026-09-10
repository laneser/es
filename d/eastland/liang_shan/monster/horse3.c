#include "../takeda.h"

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(8);
	set_name( "flower horse", "小花馬" );
	add( "id", ({ "horse" }) );
	set_short( "小花馬" );
	set_long(
		"一隻色彩斑瀾的小馬，力量好像不是很大的樣子。\n" );
	set( "unit", "只" );
	set( "value", ({ 100 , "silver" }));
	set( "weight",60);
	set_perm_stat( "str", 10 );
	set_perm_stat( "dex", 13 );
	set( "natural_armor_class", 30 );
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 20 );
	set( "alignment", 50 );
	set( "max_load", 1550 );
	set_limbs( ({ "head", "body", "feet", "tail" }) );
	set_c_limbs( ({ "頭部", "身體", "後腿", "尾巴" }) );
	set_verbs( ({ "kick" }) );
	set_c_verbs( ({  "%s撲動小雪蹄，直擊%s", "%s小花尾一甩，掃往%s" }) );

}

void init()
{
	mount::init();
}
