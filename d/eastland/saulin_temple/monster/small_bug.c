#include "../saulin_temple.h"

#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("baby mushroom", "靈芝寶寶");
	add("id",({ "baby", "mushroom" }));
	set_short("靈芝寶寶" );
	set_long(
@DESC
一隻正在啃著回陽草葉的靈芝寶寶，它正用好奇的眼光看著你。原來
這裡住了一個靈芝家族，它們把水都引走了，難怪這口井會沒水，你
想你可以向天心大師報告(report)有關發現靈芝(mushroom)家族的事。
DESC
	);
	set("unit", "只" );
	set("alignment", 250 );
	set_perm_stat("dex",10);
	set_perm_stat("str",6);
	set_perm_stat("kar",8);
	set("max_hp", 150);
	set("hit_points", 150);
	set("max_fp", 100);
	set("force_points", 100);	
	set_natural_weapon( 7, 4, 6 );
	set_natural_armor( 18, 10 );
	set("special_defense", ([ "all" : 20, ]) );
	set("unbleeding", 1);
	set("tactic_func", "sleepy" );
	set("exp_reward", 200 );
	set("alt_corpse", SAULIN_OBJ"small_pill" );
	set_c_verbs(({ "%s用身體撞%s", "%s用頭撞%s" }));
	set_c_limbs(({ "身體", "頭部" }));
	set("chat_chance",10);
	set("chat_output",({
        "靈芝寶寶眨著可愛的大眼睛說道：你是大野狼嗎？ \n",
        "靈芝寶寶眨著可愛的大眼睛說道：你是叔叔還是阿姨？\n"
    }));
    set("c_death_msg","%s突然毫無生氣地躺在地上... 不動了。\n");
}

int sleepy()
{
	object victim, mother;
	if( !(victim = query_attacker()) ) return 0;
	if( (mother = present("mami", environment())) &&
		((object)mother->query_attacker() != victim) ) {
		tell_object( victim, @ANGRY
		
站在你的身後的靈芝媽媽突然張牙舞爪的向你撲來，一面
大罵道：誰在欺負我的小孩，不想活了! 受死吧!!
	
ANGRY
 		);
 		mother->kill_ob(victim);
	}	
	if( random(20)>5 ) return 0;
    if( victim->query("stop_attack") ) return 0;
    tell_object( victim,
    	"靈芝寶寶散發出一種香氣，你感到昏昏欲睡!!\n");

    tell_room( environment(), 
    	"靈芝寶寶，把"+victim->query("c_name")+"迷的不醒人事 !!\n"
		, ({ victim, this_object() })
	);
    victim->block_attack(4);
    victim->set_temp("msg_stop_attack", 
    	"( 你現在全身無力，只想好好的睡一覺 ! )\n" 
    );
    return 1;
}

void die()
{
    object killer, mother;

	::die();
    killer = query("last_attacker");
	if( (int)killer->query_level() >= 5 ) {
    	tell_room( environment(this_object()), 
    		@C_DIE_MESSAGE
    		
你正把靈芝寶寶解決掉，突然一陣怒罵聲從你背後傳來，你轉頭一看
突然又出現一隻靈芝媽媽從你的身後張牙舞爪的向你撲來，一面大罵
道：你這麼高等級了還在欺負小孩，來嚐嚐我的厲害吧!!

C_DIE_MESSAGE
			,this_object()
		);
        if( !( mother=present("mami", environment()) ) ) {
        	mother = new( SAULIN_MONSTER"big_bug" );
        	mother->move( environment(killer) );
		}        
        mother->kill_ob(killer);
	}
}
