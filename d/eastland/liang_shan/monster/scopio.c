#include "../takeda.h"
#include "/include/move.h"
#include "conditions.h"
#include "stats.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "Red scorpion", "大紅蠍" );
	add ("id", ({ "scorpion" }) );
	set_short( "scorpion","大紅蠍");
	set("unit","尾");
	set_long("",
	   "你看到一尾非常美麗的巨大鮮紅蠍子，豔紅的表面長滿銳利的棘突\n"
	   "美麗的外表下，似乎有一股邪氣存在。\n"
	   
	);
	set( "likefish",1);
	set( "unbleeding",1);
	set("alignment",-1000);
	set_perm_stat("str", 15);
	set_perm_stat("dex", 25);
	set_perm_stat("kar",18);
	set( "aggressive", 1 );
	set( "forgetful", 1 );
	set( "time_to_heal", 8 );
	set_natural_weapon( 25, 10, 18 );
	set_natural_armor( 45, 20 );
	set ("tactic_func","poison");
	set ("race", "monster");
	set_c_limbs(({"蠍尾","蠍身","尾巴","大螯"}));
	set_c_verbs( ({"%s揮舞雙鉗襲向%s","%s毒尾往%s，狠狠螫下。"}));
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(TWEAPON"scor_whip");
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
   tell_room(environment(this_object()),
      "\n你的最後一擊命中了大紅蠍，它的尾巴無力的躺在一旁\n\n\n\n"
      "你看了覺得十分可愛，順手把它的尾巴割下來賞玩。\n"
      ,this_object() );
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die();   
}


int poison()
{
	object victim;

	if( random(20)>4 || !(victim = query_attacker()) ) return 0;
	tell_object( victim, 
		"紅蠍毒尾一甩，準確的螫中你的手腕！\n" );
	tell_room( environment(this_object()), 
		"紅蠍子蠍尾螫中" + victim->query("c_name") + "的手腕！\n",
		({ this_object(), victim }) );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 10, 10 );
	return 1;
}
