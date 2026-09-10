#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "Yang Chun", "楊春" );
	add("id",({"yang","chun"}));
	set_short( "楊春" );
	set_long(
		"他的外號是白花蛇，蒲州解陽縣人，使一把鐵瓜□，為梁山泊馬軍小彪將\n"
		"兼遠探出哨頭領．如果你不想死的話，最好別去招惹他。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -220 );
	set_perm_stat( "str", 19 );
	set_perm_stat( "dex", 21 );
	set_perm_stat( "kar", 11 );
	set_skill( "blunt", 60 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 50 );
	set( "hit_points", 300 );
	set( "max_hp", 300 );
	set( "wealth/gold", 40 );
	set( "special_defense", (["all": 23 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 22, 8 );
        set( "chat_chance",20);
	set("att_chat_output",
	"\n 楊春大喊: 愚蠢的傢伙，給我滾出梁山泊.....\n\n");
	wield_weapon( TWEAPON"ironhammer" );
        equip_armor( TARMOR"white_warcape");
        equip_armor( TARMOR"wool_hat");
        equip_armor( TARMOR"blue_cloak");
}
