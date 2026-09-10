#include "../../story.h"

inherit MONSTER;
int atk=0;
void create()
{
	::create();
	set_level(18);
	set_name( "The captain of policeman Sha","夏侯忍" );
	add( "id", ({ "captain","sha"}) );
	set_short( "京城四大名捕 夏侯忍" );
	set_long(@C_LONG
這是統領著「巫咸城」城內所有捕快的頭領。他身材魁武，皮膚拗黑，臉長著鷹勾
鼻、闊嘴和一對鷹眼，其目光銳利已極，外表冷酷無比。夏侯忍是天下四大名捕之
一，他為人老練，功夫高強，智慧深沈，極富謀略，是個相當可怕的對手，現在正
在客棧裡小憩飲酒吃些東西，手中武器仍不離身。
C_LONG
        );
	set( "gender", "male" );
	set("unit","位");
	set( "alignment", 400 );
        set_perm_stat( "str", 28 );
        set_perm_stat( "dex", 28 );
        set_perm_stat( "int", 28 );
        set_skill( "parry", 90 );
        set_skill( "thrusting", 90 );
        set_skill( "dodge", 90 );
        set("wealth/silver",1000);
        set("max_hp", 750);
        set("hit_points",750);
        set("max_fp",400);
        set("weight",900);
        set("special_defense", ([ "all":100,"none":5,"evil":50]) );
        set("aim_difficulty",
            (["critical":60,"vascular":30,"weakest":30]) );
        set_natural_armor(58,28);
        set_natural_weapon(3,5,1);
        wield_weapon(SWWEA"captain_hook1");
        equip_armor(SWARM"captain_hat1");
        equip_armor(SWARM"captain_cloth1");
        set("tactic_func","my_tactic");  
        set("chat_chance",1);
        set("chat_output",({
            "夏侯忍自語道：要不是我要負責這個城的安全，我早就殺往「妖□ 谷辰」(great_vampire)那裡去了。\n"
        }) );
        set("att_chat_output",({
          "夏侯忍狂笑：哼，你就代替「妖□ 谷辰」(great_vampire)受死吧！\n"
        }) );
        set( "inquiry", ([
          "great_vampire":"@@ask_vampire",
          "special_things":"@@ask_things"
        ]) );
}
void ask_vampire(object asker)
{
     tell_room(environment(),@LONG

夏侯忍雙目含著眼淚道：在我小的時候，一家原本高高興興地前往外公家拜年，
　　　　　　　　　　　那知途中突起颳起一陣陣的陰風，旋即繃出一個古裡古
　　　　　　　　　　　怪的僵□，只一剎那，全家橫遭慘死，只留下我一個被
　　　　　　　　　　　世外高人所救，指點原來那是個萬年僵□，名叫「谷辰
　　　　　　　　　　　」。直到現在，我仍然忘不了那段血海深仇。日前聽人
　　　　　　　　　　　談起城外遠遠南嶺外有類似僵□出沒，那僵□的樣子有
　　　　　　　　　　　點像「谷辰」，唉，無奈我有事無法分身前去。   

LONG 
   );
}
void ask_things(object asker)
{
    tell_room(environment(),"夏侯忍說道：特別的東西？我的武器就很特別啊。\n");    
}
int my_tactic()
{
    object victim;
    int i,k;
    
    if( (!victim=query_attacker())||atk||(random(20)>1) ) return 0;
    tell_room(environment(),set_color(sprintf(
       "夏侯忍奮起神威愈發抖擻精神地對著敵人發出連續攻擊！\n"),"HIW"));
    atk=1;
    k=2+random(2);
    for (i=0;i<k;i++)
      this_player()->continue_attack();
    atk=0;
    return 1;
}
