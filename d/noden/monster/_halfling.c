#include <mudlib.h>

void create(object ob)
{

    if ( !ob ) return ;
	ob->set_level(2);
	ob->set_name( "halfling girl", "半身人小女孩" );
	ob->add( "id", ({ "halfling", "girl" }) );
   ob->set_short("半身人小女孩" );
	ob->set_long(
		"這個半身人身高很矮，即使是跟其他半身人比，也算是個矮子，你\n"
		"看她稚嫩的臉孔和動作，可以確定她不會超過十歲。\n"
	);
	ob->set_perm_stat( "dex", 4 );
	ob->set( "race", "halfling" );
	ob->set( "gender", "female" );
	ob->set( "alignment", 500 );
	ob->set( "wealth/silver", 10 );

	ob->wield_weapon("/d/noden/item/spear");

	ob->equip_armor("/d/noden/item/jerkin");
}
