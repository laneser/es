#include "../takeda.h"

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(13);
	set_name( "Han Tao", "韓滔" );
	add("id",({"han","tao"}));
	set_short( "韓滔" );
	set_long(
		"他的外號是百勝將，東京人，使一條棗木槊，為梁山泊馬軍小彪將兼遠\n"
		"探出哨頭領．如果你不想死的話，最好別去招惹他。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 320 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 11 );
	set_skill( "blunt", 60 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 50 );
	set( "hit_points", 380 );
	set( "max_hp", 380 );
	set( "wealth/gold", 40 );
	set( "special_defense", (["all": 23 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 20, 8 );

	wield_weapon( TWEAPON"woodoar" );
        equip_armor( TARMOR"black_cloth");
        equip_armor( TARMOR"blue_cloak");
        equip_armor( TOBJ"jail_key");
}
