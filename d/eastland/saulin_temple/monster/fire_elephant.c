#include "../saulin_temple.h"

#include <stats.h>

inherit MONSTER;

void create()
{
	 ::create();
	 set_level(19);
	 set_name( "A Silvery fire elephant", "噴火銀象" );
	 add( "id", ({ "elephant"}) );
	 set_short( "噴火銀象" );
	 set_long(
"你看到一頭可怕的噴火巨象，它正惡狠狠地瞪著你，準備要把你烤成 Ｂａ－Ｂｉ－Ｑ"
	 );
	 set("zapped", 0);
	 set("killer", 1);
     set("pursuing", 1);
     set_perm_stat("dex", 20);
     set_perm_stat("str", 30);
     set_perm_stat("kar", 25);
     set_perm_stat("int", 15);
     set_perm_stat("pie", 20);
     set_perm_stat("con", 30);
     set_skill("dodge",  80);
     set_natural_weapon( 65, 39, 65 );
     set_natural_armor( 150, 90 );
     set("special_defense", ([ "all" : 70, "none" : 50 ]) );
     set("aim_difficulty", ([ "critical" : 50, "vascular" : 50]) );
     set("alignment",-2000);
     set("max_hp",9000);
     set("hit_points",9000);

    set("tactic_func", "breath");
    set_c_verbs(({ "%s用腿踩%s", "%s用頭撞%s", "%s用身體壓%s","%s用鼻子甩%s" }));
    set_c_limbs(({ "身體", "頭部", "腳部", "鼻子" }));
    set( "chat_chance", 5 );
    set( "att_chat_output", ({
	  "噴火銀象大叫：愚蠢的傢伙，知道我的厲害了吧!!\n",
    }) );
}

// This function is called by the magic seed
void zapped()
{
		if( query("zapped") ) return;
        set("zapped",1);
        set_natural_armor( 50, 20 );
//        calc_armor_class();
        set("max_hp",800);
        set("hit_points",800);
        set("special_defense", ([ "all" : 20, "none" : 10 ]) );
        set("aim_difficulty", ([ "critical" : 20, "vascular" : 10,]) );
        tell_room( environment(this_object()), 
@THROW
          
噴火銀象深深的吸一口氣準備噴火，舍利子飛過來，正好被它的長鼻子吸了進去!
    「哇! 鼻塞了!! 咳咳!! 哈 .. 哈 .. 哈嚏 ...」
噴火銀象打了一個大大的噴嚏，嗆咳出一團團白煙，卻再也噴不出火了。

THROW
         ,this_object());
}

void die()
{
    object killer;
    
    killer=query("last_attacker");

if( (int)killer->query_quest_level("Fire_elephant") < 1 ){
	killer->finish_quest( "Fire_elephant", 1 );
	  tell_object(killer, 
@SUCCEED

巨象慘叫一聲，一條白色的影子從它身上升起來。它一面往少林寺方向飛去一面哭道：
「嗚哇!!你欺負我!!你欺負我!!我要去叫我的主人來打你，有種你就不要跑!!!!!!」

你正不知道會不會做得太過火，突然一個影子出現在你眼前，原來是普賢菩薩。
他微笑著說：「阿彌陀佛! 善哉善哉! 多謝施主替貧僧管教那頭孽畜，貧僧無以
為報，且指引施主一條明路，倘若施主閒來無事，不妨前去雨花院摸摸(touch)
那塊頑石(stone)吧! 」
普賢菩薩說完，袍袖一揮，你感覺一陣光芒罩在你身上 ...

	[你完成了 普賢菩薩 任務，得到 15000 點經驗]

待你回過神來，菩薩已消失的無影無蹤。

SUCCEED
			);
        if ((string)killer->query("class")=="scholar") { 
           tell_object(killer,set_color("你似忽還聽到普賢菩薩對你說：賜你一隻大地精靈供你使喚，希望你能善用它。\n","HIM"));
           killer->set("demand/solid",2);
        }
	killer->gain_experience(15000);
	set("alt_corpse","NONE");
	die(1);
    } 
	else ::die();
}

void report( object attacker, object victim )
{
   string message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   tell_object( victim,"( 你"+message+" )\n");
   return;
}


int breath()
{
    object victim;
    int att_type;
    string c_name;
    if( !(victim = query_attacker()) ) return 0;

    c_name = victim->query("c_name");
    att_type = random(100);
    if( att_type < 30 ) {
	  if( this_object()->query("zapped") ) {
        tell_room( environment(this_object()), 
          "噴火銀象長鼻一伸，想要噴火攻擊"+c_name+"，但是又打了個噴嚏，只噴出一團團白煙 !\n\n"
		 , this_object() );
		return 1;
	  } else {
        tell_room( environment(this_object()), 
		  "噴火銀象長鼻一伸，把一蓬火花噴向"+c_name+"\n\n", this_object() );
		victim->receive_special_damage("fire", 50+random(12));
		report(this_object(),victim);
		return 1;
	  }
    } else if(att_type >= 30 && att_type < 50) {
      if( victim->query("stop_attack") ) return 0;
        tell_object( victim,"噴火銀象突然跺腳，把你震倒在地 !!\n");
        tell_room( environment(), 
          "噴火銀象突然跺腳，把" + victim->query("c_name") +
          "震的跌翻在地 !!\n" 
         , ({ victim, this_object() }) 
        );
        victim->block_attack(3);
        victim->set_temp("msg_stop_attack","( 你現在翻倒在地，無法攻擊 ! )\n");
        return 1;
	} else
	  return 0;
}
