
#include "../layuter.h"

inherit MONSTER ;

void create ()
{
	object helmet,boots,lance,amulet,leggings,plate,cloak;

	::create();
	set_level(14);
	set_name( "daemonic fighter", "惡魔戰士" );
	add ("id", ({ "fighter", "daemon" }) );
   set_short( "惡魔戰士" );
	set("unit","位");
   set_long(
	   " 他是當惡魔入侵精靈村時被引入迷宮的殘存惡魔族人，是一位可怕的戰士。\n"
	);
	set("alignment",-1000);
	set("wealth/gold",20);
	set_perm_stat("str", 17);
	set_perm_stat("dex", 18);
	set_perm_stat("kar",10);
	set_natural_weapon( 10, 6, 8 );
	set ("natural_armor_class", 20);
	set ("gender", "male");
	set ("race", "daemon");
	set( "tactic_func", "my_tactic" );
	set_c_verbs(({"用%s向%砍去","用%s使出必殺一擊向%s攻擊","用%s向%s刺去"}));
	set_c_limbs(({"身體","頭部","腳部","手臂"}));
       
	set_skill("parry", 75);
	set_skill("thrusting", 75);

	set("natural_defense_bonus",10);
	wield_weapon(LWEAPON"daemon_lance");      
	equip_armor(LARMOR"daemon_boots");
	equip_armor(LARMOR"daemon_amulet");
	equip_armor(LARMOR"daemon_leggings");
	equip_armor(LARMOR"daemon_plate");
	equip_armor(LARMOR"daemon_cloak");
	equip_armor(LARMOR"daemon_helmet");
}


int my_tactic()
{
	object *victim;

	if( random(20)>2 || !(victim= query_attackers()) ) return 0;
   tell_room( environment(),
		"\n惡魔戰士發出可怕的吼叫聲，並且用一種奇異的語言開始唸咒 ....\n"
           "\n你覺得眼前一黑, 某種神秘的力量擊中你的心臟, 使你痛苦不堪!\n\n",
		this_object() );
	victim->receive_special_damage( "evil", 40 );
	return 1;
}
