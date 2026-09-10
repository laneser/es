#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(2);
	ob->set_name( "swamp crab", "沼澤螃蟹" );
	ob->set_short( "沼澤螃蟹" );
	ob->set_long(
		"這是一種稀有的螃蟹，居住在沼澤和海洋的交界地帶。\n"
	);
	ob->set( "natural_armor_class", 20 );
	ob->set( "unit", "只" );
	ob->set_c_verbs( ({ "%s用它的大螯往%s一夾" }) );
	ob->set_c_limbs( ({ "身體", "硬殼" }) );
}
