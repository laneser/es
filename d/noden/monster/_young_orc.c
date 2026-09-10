#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(1);
	ob->set_name( "little orc", "小半獸人" );
	ob->add( "id", ({ "orc" }) );
   ob->set_short( "小半獸人" );
	ob->set_long(
		"這個小半獸人正對著你齜牙裂嘴。\n"
	);
	ob->set_perm_stat( "str", 3 );
	ob->set_skill( "dodge", 15 );
	ob->set_natural_armor( 10, 2 );
	ob->set( "wealth/silver", 5 );
	ob->set( "alignment", -50 );
	ob->wield_weapon( "/d/noden/item/hand_axe" );
}
