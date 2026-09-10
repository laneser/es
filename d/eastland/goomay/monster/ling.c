#include "../goomay.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "Ling", "靈兒" );
	add ("id", ({  "girl" }) );
	set_short( "靈兒" );
	set_long(
"靈兒年約二十一，一身勁裝，看似溫婉，實則聰明幹練。她正對你盈盈而笑 \n" 
"靈兒是玉女劍派弟子中的佼佼者。玉女劍派向來只收女弟子，而她們最痛恨 \n" 
"貪色不正當之徒，所以其師祖羅蘿特創『屠狼劍法』，專門用來砍殺色狼。 \n"
"靈兒自幼練習此劍法，已得其真傳，專殺天下好色之徒。 \n"
	);
	set( "alignment",1000);
	set( "gender", "female" );
	set( "race", "imp" );
	set( "unit", "位" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "piety", 25);
	set_skill("longblade",80);
	set_skill("dodge",80);
        set_skill("parry",100);
	set("defense_type","defense");
	set("special_defense", ([ "all":35, "none":25 ]) );
	set("aim_difficulty", ([ "critical":20, "vascular":27, ]) );
	set("max_hp", 500);
	set("max_fp", 1000);
	set("hit_points", 500);
	set("force_effect", 1);
	set("force_points", 1000);
	set("attack_skill","monster/sword1");
	set("wealth/gold", 100);
	set_natural_weapon(21,10,13);
	set_natural_armor( 69, 18 );
	wield_weapon( Obj"rainbow_sword" );
	equip_armor( Obj"gold_necklace" );
	equip_armor( Obj"green_cloth" );
}
