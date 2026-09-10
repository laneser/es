#include <mudlib.h>

inherit "/d/eastland/easta/monster/easta_army";

void create()
{
	::create();
	set_level(15);
	set_name( "palace guard", "宮門侍衛" );
	add( "id", ({ "guard" }) );
	set_short( "宮門侍衛" );
	set_long(
		"你看到一個保護若嵐宮的侍衛，他是隸屬於若嵐宮禁衛軍「青營」的六品武官。\n"
	);
	set( "unit", "名" );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 700 );
	set_natural_armor( 50, 15 );
	set_natural_weapon( 9, 9, 9 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 20 );
	set_skill( "longblade", 70 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 40 );
	set( "hit_points", 440 );
	set( "max_hp", 440 );
	set( "wealth/gold", 60 );
	set( "special_defense", ([ "all": 25 ]) );

	wield_weapon( "/d/eastland/easta/obj/halberd" );
	equip_armor( "/d/eastland/easta/obj/blue_armor" );
	equip_armor( "/d/eastland/easta/obj/black_boots" );
}
