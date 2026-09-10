#include "../saulin_temple.h"

#include <stats.h>

inherit "/d/eastland/saulin_temple/monster/mob_special";
//inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "The shadow of Damo", "達摩老祖的影子" );
	add( "id", ({ "shadow", "damo" }) );
	set_short( "達摩老祖的影子" );
	set_long(@C_LONG
你看見一個人 .... 喔! 不! 應該說是一個影子比較恰當，雖然他看起來濛濛
朧朧的，但是你越看它越像達摩老祖，它現在正在你的四周跳來跳去，顯得十
分高興，或許它會知道一些秘密。
C_LONG
	);
	set_perm_stat("dex", 25);
	set_perm_stat("str",25);
	set_perm_stat("kar",25);
	set_perm_stat("int",30);
	set_perm_stat("pie",20);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	set("max_hp", 690);
	set("hit_points", 690);
	set("force_points", 2000);
	set("max_fp", 2000);
	set("alignment",-1000);
	set_natural_weapon(28, 18, 32);
	set_natural_armor(70, 38);
	set("special_defense", ([ "all" : 40, "none" : 25 ]) );
	set("aim_difficulty", ([ "critical" : 50, ]) );
	set("unbleeding", 1);
	set("c_death_msg",
@MSG

 影子「颼」的一聲逃回石壁..... 「哎呀 !! 我又被困住了!! 救命啊 !!」

 影子又開始大聲呼救。當然，你是不會再上當了 !!

 「先跟我說達摩的秘密 !!」

 影子苦苦的哀求並無力的說:
 「達摩的舍利子(relic)藏在塔林，你只要到那裡召喚(call)它，
   它就會出現 !! 它可以保護你不受任何妖怪的侵襲 !!」 

 你笑嘻嘻的看著影子，不知道該不該再放它出來。
 
MSG
);
	set( "gender", "male" );
	set("chat_chance", 5);
	set("chat_output", ({
        "影子唱著跳著說: 我自由了，我自由了!\n", })
    );
	set( "inquiry", ([
		 "secret" : ({
	        "EMPTY."," 咦! 就算我知道，我為什麼要告訴你？\n"})
	]) );
        set("special_attack",(["damage_type" : "evil","main_damage" : 30,
                                "random_dam" : 20 , "hit_rate" : 25]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "那影子喃喃的唱出一些奇怪的咒文..\n"+
    "\n突然，一種邪惡的力量從你的心靈深處爆炸出來 ..\n\n");
//set("enemy_msg","The shadow utter a strange wrds and you feel headacke ... \n\n");
//set("room_msg","The shadow utter a strange words and curse " );
//set("room_msg2"," with its evil power.\n");
set("c_room_msg","那影子唱出一種邪惡的咒文，把黑暗的詛咒吹入");
set("c_room_msg2", "的心靈深處 ...\n");
}

int special_damage(object victim) 
{ 
	int dam;
	dam = 30 - (int)victim->query("alignment") / 100;
	dam = ( dam >80 ? 80 : dam );
	dam = ( dam <30  ? 30 : dam );
	return dam+random(20);
}


