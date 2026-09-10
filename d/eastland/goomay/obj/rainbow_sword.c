#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "rainbow sword", "彩虹劍" );
	add( "id", ({ "sword", "rainbow" }) );
	set_short( "the colorful sword of rainbow", "玉女門彩虹劍" );
	set_long(
		"This is the legendary weapon of Ju-nju ganger  . You\n"
		"can see many jewels  on the sword, surrounded by seven\n"
		"perfect pearl.\n",
"這把彩虹劍是昔日玉女門女俠彩虹的配劍，劍柄上鑲著七彩寶石\n"
"劍身輕而細長，極適合女子使用，劍鞘末梢還綴著七顆珍珠。\n" 
	);
	set( "unit", "把" );
	set( "type", "longblade" );
	set( "weapon_class", 35 );
	set( "min_damage", 15 );
	set( "max_damage", 32 );
	set( "weight", 80 );
	set( "value", ({ 2540, "silver" }) );
//	set( "bleeding", 13 );

	set_verbs( ({  "slash", "thrust" }) );
	set_c_verbs( ({ "用%s往%s一刺", "%s劃出一道閃亮的銀光，攻向%s",
		"的%s飛快的往%s砍去" }) );
}
