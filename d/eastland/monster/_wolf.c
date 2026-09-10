#include <mudlib.h>

void create(object ob)
{
	if ( !ob ) return ;
	ob->set_level(2);
	ob->set_name( "hyaena", "土狼" );
	ob->set_short( "土狼" );
	ob->set_long(
		"你看到一隻兇惡的土狼，對著你發出「嗚嗚」的低吼。\n"
	);
	ob->set_perm_stat( "str", 4 );
	ob->set_skill( "dodge", 20 );

	ob->set( "unit", "只" );
	ob->set_natural_weapon( 5, 3, 6 );
	ob->set( "killer", 1 );
	ob->set( "aggressive", 1 );

	ob->set_c_verbs( ({ "%s用前爪撲向%s", "%s張開滿口利齒的嘴，往%s咬去" }) );
	ob->set_c_limbs( ({ "頭部", "身體", "尾巴", "腿部" }) );
}
