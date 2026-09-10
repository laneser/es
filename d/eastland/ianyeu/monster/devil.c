#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(11);
   set_name( "sexual Devil", "萬惡淫魔" );
   add( "id", ({ "devil" }) );
   set_short( "萬惡淫魔" );
	set_long(
           "他就是東方大陸中惡名昭彰, 令人深惡痛絕的萬惡淫魔。\n"
           "不用多說, 你只要『拼命』把他宰了!\n"
	);
   set_perm_stat( "str", 12 );
   set_perm_stat( "int", 15 );
   set_perm_stat( "dex", 15 );
   set_perm_stat( "kar", 15 );
	set_skill( "dodge", 100 );
	set( "killer", 1 );
   set( "race", "daemon" );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set( "natural_armor_class", 40 );
   set( "natural_defense_bonus", 15 );
   set( "natural_weapon_class1", 20 );
   set( "natural_min_damage1", 10 );
   set( "natural_max_damage1", 15 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
        "萬惡淫魔臉上露出邪惡的笑容。\n",
        "萬惡淫魔奸笑道: 嘿嘿嘿 .... 別逃 .... 讓我吸點精氣吧!\n",
	}) );
}

int my_tactic()
{
	object *victim;
	int i;

   if( random(20)<16 || !(victim = query_attackers()) ) return 0;
   tell_room( environment(this_object()),
      "\n萬惡淫魔突然施展秘術『吸魂大法』奪去你部份的元神!\n\n",
		this_object() );
   for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "evil", 30 );
	return 1;
}

void die()
{
   object killer;

	killer = query("last_attacker");
   killer->set_temp( "kill_ian_devil", 1 );
   tell_room( environment(this_object()),
     "萬惡淫魔喊道: 噢 .... 不 .... 我還要享受美女!\n" );
   tell_object( killer,
    "\n原來『萬惡淫魔』竟躲在煙雨村, 而且還殺了自己的女兒! 真是\n"
      "人間一大悲劇! 你心想此事真殘酷, 正躊躇是否應告知(inform)\n"
      "郭長老。\n\n" );
   ::die(1);
}
