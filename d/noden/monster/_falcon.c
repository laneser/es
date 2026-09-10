#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(3);
	ob->set_name( "falcon", "獵鷹" );
   ob->set_short( "獵鷹" );
	ob->set_long(
		"這隻獵鷹正虎視耽耽地盯著你，小心不要成為它的獵物。\n"
	);
	ob->set_perm_stat( "str", 6 ); 
	ob->set_perm_stat( "dex", 5 );
	ob->set_perm_stat( "pie", 1 );

	ob->set( "unit", "只" );
	ob->set( "alignment", 150 );
	ob->set( "natural_weapon_class1", 3 );
	ob->set( "natural_min_damage1", 3 );
	ob->set( "natural_max_damage1", 5 );
	ob->set_c_verbs( ({ "%s往下俯衝，用嘴巴啄%s", "%s用爪子往%s抓下" }) );
	ob->set_c_limbs( ({ "頭部", "身體", "翅膀" }) );
}
