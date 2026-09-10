#include "../../story.h"
inherit MONSTER ;

void create ()
{
	::create();
	set_level(18);
	set_name( "Scholar of palace", "巫禮" );
	add ("id", ({ "scholar"}) );
	set_short( "文官 巫禮");
	set_long(@CLONG
這是一位溫文儒雅、彬彬有禮的謙謙君子。他生就一副道貌岸然的樣子，兩眉下垂
分得極開，臉頰修長，雖然毛髮業已斑白，兩個眸子卻炯炯有神，精神好極了。他
的舉止談吐相當不凡，字字珠璣，橫生妙趣，恨不得與他多談一會兒多增長些見聞
。他現在正與一旁的文官談論著。
CLONG
	);
	set("race","巫師");
	set("gender","male");
	set_perm_stat("str", 25 );
        set_perm_stat("dex", 20 );
        set_perm_stat("int", 28 );
	set( "alignment", 500 );
	set( "hit_points", 700 );
	set( "max_hp", 700 );
        set( "max_fp",200);
        set("weight",800);
	set_natural_armor( 38, 30 );
        set("aim_difficulty",([ 
    	  "critical":70,"vascular":40,"ganglion":40,"weakest":40 ]) );
        set("wealth/gold",40);
        set("stun_difficulty",50);
        set_skill("parry",85);
        set_skill("dodge",85);
        set_skill("anatomlogy",40);
        set_skill("thrusting",100);
        set_skill("two-weapon",100);
        set("aiming_loc","ganglion");
        set("tactic_func","my_tactic");
        set("tactic","melee");
        set_natural_weapon(20,6,15);
        set_natural_weapon2(29,6,15);
        wield_weapon(SWWEA"wiz_pen1");
        wield_weapon2(SWWEA"wiz_pen1");
        equip_armor(SWARM"wiz_belt1");
        equip_armor(SWARM"wiz_cloth1");
        set("special_defense",(["all":30,"none":30]));
}
int my_tactic()
{
   object victim;
   if ( !victim=query_attacker() ) return 0;
   if ( random(10) > 1 ) return 0;
   tell_room(environment(this_object()),
      set_color("巫禮手上的金筆迸射出萬丈金光！\n\n\n","HIY"));   
   victim->receive_special_damage("divine",30+random(30));
   return 1;
}