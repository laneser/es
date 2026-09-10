#include <mudlib.h>

void create(object ob)
{
	if (!ob ) return ;
	ob->set_level(1);
	ob->set_name( "beetle", "甲蟲" );
   ob->set_short( "甲蟲" );
	ob->set_long(
		"一隻長著硬殼的長角甲蟲，讓你想起小時候 ....。\n"
	);
	ob->set_perm_stat( "str", 3 );
   ob->set( "race", "insect" );
	ob->set( "unit", "只" );
	ob->set( "alignment", -150 );
	ob->set( "natural_weapon_class1", 3 );
	ob->set( "natural_min_damage1", 2 );
	ob->set( "natural_max_damage1", 4 );
	ob->set_c_verbs( ({ "%s用角往%s一頂", "%s張開大牙，往%s咬去" }) );
	ob->set_c_limbs( ({ "頭部", "身體", "腳部", "甲殼" }) );
}
