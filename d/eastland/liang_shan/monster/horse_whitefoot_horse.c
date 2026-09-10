#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(15);
	set_name( "whitefoot_horse", "踏雪烏騅" );
	add( "id", ({ "horse" }) );
	set_short(  "踏雪烏騅" );
	set_long(
		"一隻健壯的黑色馬，但它的四隻腳卻是白的。\n" );
	set( "unit", "只" );
	set_perm_stat( "int", 10 );
	set_perm_stat( "str", 22 );
	set( "natural_armor_class", 70 );
	set( "natural_weapon_class1", 40 );
	set( "natural_min_damage1", 25 );
	set( "natural_max_damage1", 35 );
	set( "alignment", 100 );
	set( "max_load", 2450 );
	set_c_limbs( ({ "頭部", "身體", "後腿", "尾巴" }) );
	set_c_verbs( ({  "%s撲動雪蹄，片片雪花砸向%s", "%s雲尾一甩，一朵烏雲直罩%s" }) );

}

void init()
{
//	monster::init();
	mount::init();
}