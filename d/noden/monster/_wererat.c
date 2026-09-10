#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(3);
	ob->set_name( "wererat", "鼠人" );
   ob->set_short( "鼠人" );
	ob->set_long(
		"這傢伙長得一副獐頭鼠目的樣子，身上長滿棕黑色的毛。\n"
	);
	ob->set( "gender", "male" );
	ob->set( "alignment", -400 );
	ob->set( "aggressive", 1 );
	ob->set( "wealth/silver", 40 );
	ob->set( "natural_armor_class", 20 );
	ob->set( "natural_defense_bonus", 6 );
	ob->set_perm_stat( "dex", 6 );
	ob->set_skill( "dodge", 30 );

	ob->wield_weapon("/d/noden/item/baselard");
}
