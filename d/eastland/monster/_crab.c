#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return;
	ob->set_level(1);
	ob->set_name( "little crab", "小螃蟹" );
	ob->set_short( "小螃蟹" );
	ob->set_long(
		"這隻螃蟹雖然很小，但是這個沙灘也是足夠讓它橫行的地方。\n"
	);
	ob->set( "natural_armor_class", 10 );
	ob->set( "unit", "只" );
	ob->set_c_verbs( ({ "%s用它的大□往%s一夾" }) );
	ob->set_c_limbs( ({ "身體", "硬殼" }) );
}
