#include <mudlib.h>
#include "../../story.h"
#include <conditions.h>
#include <stats.h>
inherit MONSTER ;
int time=0;
void create ()
{
	::create();
	set_level(18);
	set_name( "The ice-monster Lady", "寒玉娘娘" );
	add ("id", ({ "monster","ice-monster","lady","Lady"}) );
	set_short("雪山靈魅 寒玉娘娘");
	set_long(@CLONG
你眼前所見的是一位身蒙輕紗的赤身妖女，眼送秋波，小嘴嗔弩，一副惹人憐惜的
樣子；她渾身生得膚如凝脂，腰似細柳，通體裸露；粉彎雪股、嫩乳酥胸，隔著一
層輕紗，宛如霧裡看花，更增撫媚妖□，動人已極。尤妙是那玉腿圓滑，柔肌光潤
；白足如霜，脛趾豐妍；底平趾斂，春蔥欲折；妙處隱隱畢現，容易惹人情思，活
色生春，從所未睹。
CLONG
	);
	set("gender","female");
	set("race","冰妖");
	set_perm_stat("str", 25 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 20 );
        set_perm_stat("int", 28 );
	set("killer",1);
	set( "alignment", -1000 );
	set( "hit_points", 900 );
	set( "max_hp", 900 );
        set( "max_fp",400);
	set_natural_weapon( 35, 17, 30 );
	set_natural_armor( 85, 9 );
        set("aim_difficulty",([ 
    	  "ganglion":50,"critical":70,"weakest":30 ]) );
        set("stun_difficulty",100);
        set("unbleeding",1);
        set_skill("dodge",90);
        set_skill("parry",90);
        set_skill("dagger",90);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"ice_dagger");
        equip_armor(SWARM"ice_ring");
        set("special_defense",(["all":100,"none":40,"fire":-30]));
}
int my_tactic()
{
    int i;
    object victim,env,flowob;
    string power,name;
    if ( !victim=query_attacker() ) return 0;
    env=environment(this_object());
    name=victim->query("c_name");
    if ( time ) {
       if ( time>1 ) { 
         tell_room( env,sprintf(
            "寒玉娘娘張開利牙咬住%s的脖子，一片吮啜之聲，原來她正在吸取%s的鮮血...\n"
            ,name,name),victim);
         tell_object(victim,"寒玉娘娘張口往你脖子一咬，正在吸取你的鮮血...\n");
         (CONDITION_PREFIX + "bleeding")->apply_effect(victim,10,2);
       }
       else tell_room( env,"寒玉娘娘臉露滿足的表情口角處兀自滴著鮮血！\n");         
       time--;
       return 0;
    }
    switch( random(35) ) {
    case 0..1:
        tell_room(env,sprintf("寒玉娘娘正在對著%s施展攝魂大法！\n",name),victim);
        tell_object(victim,"寒玉娘娘正在對你施展攝魂大法，！\n\n");
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack","(  你被寒玉娘娘迷住了  )\n");
        return 0;
    case 2..3 :
        time=6+random(1);
        break;    
    case 4..5:
       tell_room(env,sprintf("寒玉娘娘往前一揮，陣陣寒氣襲向%s!\n",name),victim);
       tell_object(victim,"\n你的護身氣勁被一股寒氣突破，你中了寒毒了！！\n\n");
       (CONDITION_PREFIX + "simple_poison")->apply_effect(victim,7,10);
    default :
        break;
    }
    return 0;
}

