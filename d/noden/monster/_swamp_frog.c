#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(6);
	ob->set_name( "swamp frog", "沼澤蛙" );
	ob->add( "id", ({ "frog" }) );
   ob->set_short( "沼澤蛙" );
	ob->set_long(
		"一隻又大又黏的綠色沼澤蛙正一動也不動地趴在沼澤的爛泥裡。\n"
	);
	ob->set( "unit", "只" );
	ob->set( "alignment", 500 );
	ob->set_skill( "anatomlogy", 30 );
	ob->set_temp( "aiming_loc", "ganglion" );
	ob->set_c_limbs( ({ "後腿", "頭部", "身體" }) );
	ob->set_c_verbs( ({ "%s張嘴往%s一咬", "%s用它的舌頭往%s一舔" }) );
	ob->set_natural_armor( 10, 15 );
	ob->set_natural_weapon( 10, 8, 11 );
}
