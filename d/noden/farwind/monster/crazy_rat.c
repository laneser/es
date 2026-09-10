#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "crazy rat", "瘋老鼠" );
	add( "id", ({ "rat" }) );
	set_short( "瘋老鼠" );
	set_long(@CLONG
這隻老鼠看起來似乎瘋了，雙眼中閃爍著血紅色的神采，你注意到它的脖子
上好像掛著什麼東西。
CLONG
	);

	set_perm_stat("dex", 10 );
	set_perm_stat("str", 12 );
	set_skill( "dodge", 50 );

	set_c_verbs( ({ "%s用爪子亂抓%s", "%s張嘴往%s咬下",
		"%s抬起後腿，踢向%s", "%s向前猛竄，用爪子在%s亂挖" }) );
	set_c_limbs( ({ "頭部", "身體", "前爪", "後腿", "尾巴" }) );

	set( "aggressive", 1 );
	set( "unit", "只" );
	set( "natural_armor_class", 25 );
	set( "natural_weapon_class1", 14 );
	set( "natural_min_damage1", 6 );
	set( "natural_max_damage1", 6 );
	set( "max_hp", 160 );
	set( "hit_points", 160 );
}
