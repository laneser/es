#include <mudlib.h>

void create(object ob)
{
    if (!ob ) return ;
	ob->set_level(3);
	ob->set_name( "fat boar", "野豬" );
	ob->add( "id", ({ "boar" }) );
   ob->set_short( "野豬" );
	ob->set_long(
		"這頭野豬實在很胖，胖到你幾乎把它誤認為別人飼養的豬。\n"
	);
	ob->set_perm_stat( "str", 5 );
	ob->set_perm_stat( "dex", 2 );
   ob->set( "race", "beast" );
	ob->set( "unit", "頭" );
	ob->set( "natural_weapon_class1", 7 );
	ob->set( "natural_min_damage1", 3 );
	ob->set( "natural_max_damage1", 8 );
	ob->set_c_verbs( ({ "%s低頭猛衝，撞向%s", "%s在地上一滾，用牙齒往%s頂去" }) );
	ob->set_c_limbs( ({ "頭部", "身體", "腿部", "屁股" }) );
}
