// /d/noden/hawk/monster/scout.c

#include <mudlib.h>
#include "../hawk.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name("hawkman warrior", "鳥人族戰士");
	add( "id", ({"hawkman", "warrior"}) );
	set_short("鳥人族戰士");
	set_long(
		"你看到一位鳥人族的戰士，他正用一塊破布在擦盾。\n"
	);
	set( "gender", "male" );
	set( "race", "hawkman" );
	set( "alignment", 200 );
	set_natural_armor( 30, 2 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_skill( "longblade", 70 );
	set_skill( "parry", 70 );
	set_skill( "block", 30 );
	set_skill( "dodge", 30 );
	set( "wealth/silver", 200 );

	wield_weapon( WEAPON"stone_sword" );
	equip_armor( ARMOR"stone_shield" );
	equip_armor( ARMOR"leather_hauberk");
}
