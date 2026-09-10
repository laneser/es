#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "grey rat", "灰老鼠" );
	add( "id", ({ "rat" }) );
	set_short( "灰老鼠" );
	set_long(
		"一隻又大又肥的灰老鼠，看起來很髒。\n"
	);
	set_perm_stat("dex", 3 );
	set_perm_stat("str", 3 );
	set_c_verbs( ({ "%s用爪子亂抓%s", "%s張嘴往%s咬下" }) );
	set_c_limbs( ({ "頭部", "身體", "前爪", "後腿", "尾巴" }) );

	set( "natural_armor_class", 10 );
	set( "natural_weapon_class1", 5 );
	set( "natural_min_damage1", 2 );
	set( "natural_max_damage1", 2 );
}
