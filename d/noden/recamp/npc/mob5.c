
#include <mudlib.h> 
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "brontosaurus statue", "雷龍雕像" );
	add("id",({"statue"}));
	set_short( "雷龍雕像" );
	set_long(
   "你看到一隻巨大的雷龍雕像，樣子有點像真的一樣，雖然很舊了，卻仍能感覺\n"
   "一雙滴溜溜的眼珠子正盯著你瞧著。\n"
	);
	set( "alignment", -800 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 70 );
        set("unbleeding",1) ;
        set("weight",350) ;
        set("exp_reward",900) ;
	set( "tactic_func", "my_tactic" );
        set( "max_hp", 300 );
        set("hit_points",300) ;
}

int my_tactic()
{
  object victim;

    if( random(50)<30 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,"( 你發現被電的毫無力氣! )\n" );
      tell_room(environment(victim),
          "你發現"+victim->query("c_name")+
          "被電的毫無力氣!\n", victim);
      victim->block_attack(3) ; 
      victim->set_temp("msg_stop_attacker","( 你發現被電的毫無力氣! )\n") ; 
      return 1;
}

int accept_item(object who,object item)
{
  int code ;

  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) code = 1 ; else 
  if (!(who->query_temp("lulu_active"))) return 1 ;  

    write("\n突然一陣耀眼的光芒照亮的讓你幾乎看不清楚眼前的東西......\n") ;
    write("咦？你不禁懷疑自己是不是眼花了...怎麼雕像竟然動了？\n") ;

// 把布片收起來*grin*
   item->remove();
    tell_object( who,"雕像說道: 謝謝！為了報答你就讓我送你上西天吧!!\n");
   kill_ob(who);
   if( who ) who->set_explore("noden#39");
    return 1;
}

