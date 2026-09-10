#include "../dony.h"

inherit MONSTER;

#include <stats.h>
#include <conditions.h>

void create()
{
	::create();
	set_level(15);
	set_name( "the younger of couples", "鷹老" );
	add("id",({"couple","couples","younger"}) );
        set_short( "天山二老 鷹老" );
	set_long(@C_LONG
天山二老在江湖上極具身份與地位, 十多年前一役擊殺為害多時的『廣東六虎』,
更而倍受武林人士所推祟。鷹老是天山二老中較年輕者, 看起來矮矮胖胖的,他的
雙手尖而有力練得是一套大擒拿手法,被他擒住都是難逃九死一生。他偕著鶴老來
參加丐幫祭祖大典,順便要向其它武林人士討教一番。
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set( "time_to_heal", 7 );
	set_natural_armor( 35, 18 );
	set_natural_weapon( 40, 17 , 29);
	set("max_hp",500);
	set("hit_points",500);
	set("force_points",400);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 25 );
	set_skill( "parry",30 );
	set( "wealth/silver",150);
	set( "special_defense", ([ "all": 20 ]) );
	set( "aim_difficulty",(["critical":60,"vascular":30,"weakest":50]) );
	set("couple",1);
        set_c_verbs( ({ "%s使出『 大 悲 手 』第一式, 拍向%s要害",
                        "%s以退為進使出『 大 悲 手 』第二式, 雙手舞成一個圓撲向%s",
                        "%s暴吼一聲, 『 大 悲 手 』第三式向%s遞了過來",
                        "%s猛地使出『 大 悲 手 』最強一式, 漫天人影向%s直攻而來"
                      }) ); 
        equip_armor(DARMOR"couple_cloak");
        set( "tactic_func", "my_attack" );
        set( "chat_chance", 20 );
        set( "att_chat_output", ({
                 "天山二老 鷹老狂笑道:又有一個找死,正好拿你來試試我的新掌法!! \n"
            }) );
} 

int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
        return 0;
}


int my_attack()
{ 
    object *couples,victim;
    int i;
    
    victim = query_attacker();
    if( !victim ) return 0;
    
    couples = filter_array( all_inventory(environment(this_object())),
           "can_help", this_object() );
    for( i=0; i<sizeof(couples); i++ ) {
        tell_room( environment(this_object()), couples[i]->query("c_name")+
            "怒道:我們豈是那麼好欺負的,給我下地獄去吧!!\n",couples[i]);
        couples[i]->kill_ob(victim);
    }

    if( random(20)>4 ) return 0;
    if( victim->query("stop_attack") ) return 0;
    
    tell_room( environment(this_object()),
              "\n\n鷹老施展『 大 擒 拿 手 』把"+
               victim->query("c_name")+"狠狠的抓住令他動彈不得!!\n",victim);
    tell_object( victim,"\n\n"+this_object()->query("c_name")+
              "施展『 大 擒 拿 手 』把你狠狠的抓住,令你動彈不得!!\n");
    victim->block_attack(10);
    victim->set_temp("msg_stop_attack","(  你被擒住了,動彈不得 !!  )\n");
    return 1;
}

