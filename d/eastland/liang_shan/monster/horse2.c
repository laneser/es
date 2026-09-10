#include <mudlib.h>

inherit MONSTER;
inherit MOUNT;

void create()
{
	::create();
	set_level(12);
	set_name( "whitefoot horse", "烏雲踏雪" );
	add( "id", ({ "horse" }) );
	set_short( "烏雲踏雪" );
	set_long(
		"一隻黑色的小馬，但它的四隻腳卻是白的。\n" );
	set( "unit", "只" );
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 18 );
	set( "natural_armor_class", 30 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 25 );
	set( "alignment", 100 );
	set( "max_load", 2300 );
	set_limbs( ({ "head", "body", "feet", "tail" }) );
	set_c_limbs( ({ "頭部", "身體", "後腿", "尾巴" }) );
	set_verbs( ({ "kick" }) );
	set_c_verbs( ({  "%s撲動雪蹄，片片雪花砸向%s", "%s雲尾一甩，一朵烏雲直罩%s" }) );

}

void init()
{
	mount::init();
}