
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name("black-claw zombie", "烏爪僵□");
	add( "id", ({ "zombie","black-claw" }) );
   set_short( "烏爪僵□" );
	set_long(
"烏爪僵□是被超渡失敗的壞人,因怨恨無法消滅而變成的疆□...\n"
"它是從極端的憤恨中產生的怨靈，最喜歡用黑黑的爪子抓住別人...\n"
"它要找一個替身,才能脫離可怕的地獄... 它正輕輕的對著你噴氣呢!!!\n"
	);
	set( "unit", "只" );
	set( "alignment", -1000 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 4, 1, 2 );
	set_perm_stat( "int", 1 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "str", 3 );
	set_skill("dodge",15);
   set( "killer", 1 );
	set( "pursuing", 1 );
	set( "tactic_func", "block" );
	set_c_limbs( ({ "半截頭顱", "烏黑的身子", "滿是蛆的腿", "快斷掉的耳朵" }) );
	set_c_verbs( ({ "%s伸出汙黑的爪子，抓向%s","%s伸長舌頭舔向%s", }) );
        set("alt_corpse","/d/monk/monster/corpse1.c"); 
        set("c_death_msg","僵□被你殺死後化成一灘血水... \n"); 


}

int block()
{
	object victim;

	if( random(20)>5 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object( victim, 
"烏爪僵□突然伸長它的手臂，緊緊的掐住你的脖子說著.... 『還...我..命...來!』 \n\n");
	tell_room( environment(), 
"僵□黑爪暴伸 ，牢牢的掐住了" + victim->query("c_cap_name") + "的脖子！\n",
		({ victim, this_object() }) );
	victim->block_attack(4+random(4));
	victim->set_temp("msg_stop_attack", 
"( 你的脖子被掐住,連氣都喘不過來了! )\n" );
	return 1;
}
