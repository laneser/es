#include "saulin_monk.c"

void create()
{
	::create();
	set_level(17);
	set_name( "master kon gun", "戒律院首座 空剛" );
	add ("id", ({ "master", "kon", "gun","kon gun" }) );
	set_short( "戒律院首座 空剛" );
	set_long(
@C_LONG
戒律院負責少林眾僧之戒規懲處，所有僧人回寺後的第一件事便是赴戒律院
報告此行雲遊的功過。空剛人如其名，性格剛烈，無懼任何邪惡豪強。他曾
一人單挑武夷十三怪，奮戰三天，浴血而回... 所以他被方丈選為戒律堂首
座。
C_LONG
	);
	set( "alignment",1600);
	set( "gender", "male" );
	set( "race", "human" );
	set( "unit", "位" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 21 );
	set_skill("unarmed",100);
	set_skill("block",90);
	set_skill("parry",80);
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 999);
	set("max_fp", 500);
	set("hit_points", 999);
	set("force_points", 500);
	set("wealth/gold", 50);
	set_natural_weapon( 25, 24, 37 );
	set_natural_armor( 45, 40 );
	set("weight", 500);
	set("chat_chance", 10);
	set("chat_output", ({
		"空剛說: 少林寺僧當守五戒: 戒妄語, 戒淫邪, 戒飲酒 .....\n",
	}) ); 
	set("att_chat_output", ({
	    "空剛合十道：「施主於我少林寺大開殺戒，就讓我空剛來渡化你吧 !」\n",
	}) );
	set("attack_skill",CLASS"dragon_claw");
	set("monk_gonfu/dragon-claw",10);
//	wield_weapon( SAULIN_OBJ"go.c" );
	equip_armor( SAULIN_OBJ"cloth2a.c" );
//	equip_armor( SAULIN_OBJ"shield2.c" );
	equip_armor( SAULIN_OBJ"armband1.c" );
}
