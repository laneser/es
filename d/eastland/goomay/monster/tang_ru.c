
#include <../goomay.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name("tang ru", "唐如");
	add( "id", ({ "ru","tang" }) );
	set_short("唐如");
	set_long(
"唐如是遠從四川跑來古梅鎮玩的小女孩， 她大概只有十五、六歲的樣子，\n"+
"十分活潑可愛。她似乎很少出門，正一個人開開心心的四處東看西看...\n"  
	);
        set("race","human");
        set("gender","female");	
        set("wealth",(["silver":50])); 
        set( "unit", "位" );
	set( "alignment", 200 );
	set_natural_armor( 35, 14 );
	set_natural_weapon( 11, 8, 17 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "pie", 2 );
	set_perm_stat( "dex", 9 );
	set_skill("dodge",35);
	set( "pursuing", 1 );
	set( "tactic_func", "emit_poison" );
	equip_armor(Obj"tang_ring");
} 

int emit_poison()
{
	object victim;

	if( random(25)>6 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
"唐如嬌笑道 『讓你瞧瞧四川唐門的厲害!!!』\n"
"纖手一揚，你的眼前突然爆出一團粉紅色的煙霧, 你感到一陣暈眩。\n\n" 
 , 	 
	this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 7, 7 );
	return 1;
}
