#include <mudlib.h>

inherit MONSTER;
int is_zapped = 0;

void create()
{
	::create();
	set_level(13);
	set_name( "devil boy", "惡魔少年" );
	add( "id", ({ "boy" }) );
	set_short( "惡魔少年" );
	set_long(
		"這個小男孩有黑色的眼珠和紅色的頭髮，他的額頭上有一個惡魔的標記，當\n"
		"你的視線接觸到他的眼睛時，你看到因邪惡而散發出的光彩。\n"
	);
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 18 );
	set_skill( "dodge", 100 );
	set( "killer", 1 );
   set( "race", "daemon" );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set( "natural_armor_class", 40 );
	set( "natural_defense_bonus", 200 );	// You need an incantation to change this *grin*
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 11 );
	set( "natural_max_damage1", 20 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
		"惡魔少年說道: 嘿嘿嘿 .... 你既然見到了我，就別想活命！\n",
		"惡魔少年臉上露出邪惡的笑容。\n",
		"惡魔少年歇斯底里地發出夢囈般的怪叫: 殺呀！殺呀！殺呀！\n"
	}) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( random(20)<18 || !(victim = query_attackers()) ) return 0;
	tell_room( environment(this_object()), 
		"惡魔少年喃喃地念著詭異的咒文，使你覺得心臟絞痛！\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "evil", 30 );
	return 1;
}

// This function is called by the incantation of exorcise
void zapped()
{
	is_zapped = 1;
	set( "natural_defense_bonus", 20 );
	calc_armor_class();
	tell_room( environment(this_object()), 
		"惡魔少年一見到驅魔咒，大聲尖叫: 該死的傢伙！把那個東西拿開！\n" ,
		this_object() );
}

void die()
{
        object killer;
	killer = query("last_attacker");
	if( is_zapped ) {
		killer->set_temp("devil_killer",1);
		::die();
	}
	else {
		tell_room( environment(this_object()), 
			"惡魔少年咳出幾口鮮血，倒在地上 ....\n\n"
			"你聽到一陣沙啞的聲音從惡魔少年的屍體發出: 「你以為這樣就完了嗎？休想！」\n\n"
			"惡魔少年的屍體又站了起來！\n\n" ,
			this_object() );
		set( "exp_reward", 1 );
		set( "alt_corpse", "/d/noden/house/monster/devil" );
		::die(1);
	}
}
