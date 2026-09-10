#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "rat", "老鼠" );
	set_short( "a rat", "老鼠" );
	set_long(
		"A small rat. It looks pretty hungry.\n",
		"一隻瘦小的老鼠，看起來好像餓了很久。\n"
	);
	set_perm_stat("dex", 3 );
	set_perm_stat("str", 2 );

	set_c_verbs( ({ "%s用爪子亂抓%s", "%s張嘴往%s咬下" }) );
	set_c_limbs( ({ "頭部", "身體", "前爪", "後腿", "尾巴" }) );

	set( "unit", "只" );
	set( "natural_armor_class", 8 );
#include <replace_mob.h>
}
