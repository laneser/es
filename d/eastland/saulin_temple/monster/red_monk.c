#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "rohan of red pallium", "羅漢堂紅衣羅漢" );
	add( "id", ({ "monk","rohan" }) );
	set_short( "羅漢堂紅衣羅漢" );
	set_long(
		"你看到一名羅漢堂的紅衣羅漢，他正在守衛羅漢堂。\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment",  1500 );
	set("max_hp", 465);
	set("hit_points", 465);
	set("max_fp", 1800);
	set("force_points", 1800);
	set_natural_weapon( -15, -10, -5 );
	set_natural_armor( 45, 28 );
	set( "wealth/gold", 15 );
	set_perm_stat( "str", 21 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "con", 25 );
	set("special_defense", ([ "all" : 25, "none" : 7 ]) );
	set("aim_difficulty", ([ "critical" : 30, "vascular" : 25, ]) );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set("defense_type","parry");
	set("attack_skill",CLASS"wu_sur");
	set("gonfus/wu_sur",100);
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
         "羅漢堂紅衣羅漢大叫:「有我們羅漢堂弟子在，休想侵犯羅漢堂 ！」\n",
		 "羅漢堂紅衣羅漢大叫:『師兄弟們! 那些無恥的壞蛋在這裡!!快來教訓他們!』\n",
		 })
	 );

	wield_weapon( SAULIN_OBJ"blade3" );
	equip_armor( SAULIN_OBJ"red_pallium" );
//	equip_armor( SAULIN_OBJ"eye" );
	equip_armor( SAULIN_OBJ"glove3a" );
}

