#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(14);
	ob->set_name( "bandit", "土匪" );
	ob->set_short( "土匪" );
	ob->set_long(@C_LONG
這個土匪生得濃眉大眼，虎背熊腰，腰間掛著一把鬼頭刀，如果你不想
死的話，最好別去招惹他。
C_LONG
	);
	ob->set( "race", "human" );
	ob->set( "gender", "male" );
	ob->set( "alignment", -400 );
	ob->set_perm_stat( "str", 24 );
	ob->set_perm_stat( "dex", 16 );
	ob->set_perm_stat( "kar", 10 );
	ob->set_skill( "longblade", 80 );
	ob->set_skill( "parry", 80 );
	ob->set_skill( "dodge", 50 );
	ob->set( "hit_points", 400 );
	ob->set( "max_hp", 400 );
	ob->set( "wealth/gold", 75 );
	ob->set( "special_defense", (["all": 25 ]) );
	ob->set_natural_weapon( 8, 8, 8 );
	ob->set_natural_armor( 40, 10 );

	ob->wield_weapon( "/d/eastland/obj/skull_glaive" );
}
