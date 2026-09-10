
#include <mudlib.h> 
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "tyrannosaurus statue", "暴龍雕像" );
	add("id",({"statue"}));
	set_short( "暴龍雕像" );
	set_long(
          "你看到一箇中型的暴龍雕像，也許長久暴露於戶外的關係，已經\n"
          "斑痕點點了。\n"
	);
	set( "alignment", -800 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 70 );
        set("unbleeding",1) ;
        set("weight",350) ;
        set("exp_reward",800) ;
	set( "tactic_func", "my_tactic" );
        set( "max_hp", 300 );
        set("hit_points",300) ;
}

int my_tactic()
{
  object victim;

    if( random(20)<15 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,
        "雕像身形急轉，你感到臉上熱辣，臉上已經掛彩了！\n"
      );
      tell_room(environment(this_object()),
        "雕像身形急轉向"+victim->query("c_name")+"臉上攻去去.\n"
          ,this_object() );
      victim->receive_special_damage("fire",10+random(5));
      "/d/magic/magic"->report(this_object(),victim);

      tell_object(victim,"( 你發現麻麻的毫無力氣! )\n" );
      tell_room(environment(victim),
          "你發現"+victim->query("c_name")+
          "麻痺而毫無力氣!\n", victim);
      victim->block_attack(2) ; 
      victim->set_temp("msg_stop_attacker","( 你發現麻痺而毫無力氣! )\n") ; 
      return 1;
}

int accept_item(object who,object item)
{
  int code ;

  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) code = 1 ; else 
  if (!(who->query_temp("lulu_active"))) return 1 ;  

    command("give paper to "+who->query("name"));
    write("\n突然一陣耀眼的光芒照亮的讓你幾乎看不清楚眼前的東西......\n") ;
    write("咦？你不禁懷疑自己是不是眼花了...怎麼眼前多了個陌生的男子？\n") ;

    tell_room( environment(), 
       sprintf("陌生人向%s(%s)點頭微笑，說道: 謝謝！\n",
       who->query("c_name"),who->query("name") ), who ) ;

    set("alt_corpse",CAMPMOB"mob4-1") ;
    if (code==1) return 1 ; 
    if (!(who->query_temp("lulu_mob4"))) { 
      who->set_temp("lulu_mob4",1) ;
    }
    if ( (who->query_temp("lulu_mob2")) && (who->query_temp("lulu_mob3")) ) 
          tell_object( who,"陌生人說道: 謝謝！請把他交給露露吧!!\n");
    else  tell_object( who,"陌生人說道: 謝謝！請再尋找其他將軍吧!!\n");

    die() ;
    return 1;
}

void die()
{
   ::die(1) ;
   return;
}
