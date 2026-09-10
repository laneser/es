
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(3);
	set_name("8-claw zombie", "八爪僵□");
	add( "id", ({ "zombie","8-claw" }) );
	set_short("A 8-claw zombie", "八爪僵□");
	set_long(@C_LONG
八爪僵□是被超渡失敗的壞人,因怨恨無法消滅而變成的疆□...
它上輩子是千年蜘蛛精投胎的，最喜歡用八個爪子抓住別人...
它要找一個替身,才能脫離可怕的地獄... 它正輕輕的對著你噴氣呢!!!
C_LONG	);
	set( "unit", "只" );
	set( "race", "undead" );
	set( "alignment", -400 );
	set_natural_armor( 10, 4 );
	set_natural_weapon( 4, 2, 4 );
	set_perm_stat( "int", 1 );
	set_perm_stat( "pie", 1 );
	set_perm_stat( "dex", 2 );
	set_perm_stat( "karma", 1 );
	set_perm_stat( "str", 3 );
	set_skill("dodge",15);
        set("defense_type","berserk");
	set( "pursuing", 1 );
	set( "tactic_func", "block" );
	set_c_limbs( ({ "半截頭顱", "烏黑的身子", "滿是蛆的腿", "快斷掉的耳朵" }) );
	set_c_verbs( ({ "%s伸出尖尖的爪子，抓向%s","%s伸長枯骨做的手臂，抓向%s", "%s大聲的笑著說『老禿驢受死吧!』，雙爪劈向%s", }) );
        set("alt_corpse","/d/monk/monster/corpse1"); 
        set("c_death_msg","八爪僵□被你殺死後化成一灘血水... \n"); 


}

int block()
{
	object victim;
        int i;
        
	if( random(20)>5 || (!i) || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_object( victim,
"\n\n八爪僵□突然露出醜陋的奸笑，哇!!! 它身後出現了另外六隻手臂 \n\n");
	tell_room( environment(), 
sprintf("\n八爪僵□突然背上長出了另外六隻手，一起抓向%s的脖子！\n",victim->query("c_name")),
		({ victim, this_object() }) );
  	for(i=0;i<6;i++)
            this_object()->continue_attack();	
	return 1;
}
