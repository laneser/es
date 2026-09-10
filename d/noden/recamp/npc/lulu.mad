
#include <mudlib.h>
#include "../camp.h"
inherit TEACHER;
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "lulu", "露露" );
        add ("id",({ "lulu" }));
        set_short( "露露");
        set("unit","位");
        set_long(
@C_LONG
哇！長的真是亂正點的！長髮披肩，柳眉杏眼，唇紅齒白，細皮嫩肉，穿著迷人的
三點式魔法師戰鬥服裝，更將玲瓏的身材曲線及渾圓飽滿的胸部，完全表現無遺，
真是充滿著野性的青春與美麗！
C_LONG
);
        set ("gender", "female");
        set ("race", "orc");
        set_natural_armor( 50, 20 );
	set_natural_weapon(25,5,15 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 30 );
        set_perm_stat( "dex", 30 );
   set_skill( "camp", 100 );
   set_lessons( ([ "camp" : ({ 50, 100 }) ]) );
        set_skill( "parry", 100 );
        set_skill("dodge",80) ;
	set("hit_points",1500);
	set("max_hp",1500);
	set( "wealth/silver",1500);
        set("aim_difficulty",
          (["critical":80,"vascular":50,"weakest":80,"ganglion":80])) ;
        set("weight",1000) ;
        set("c_death_msg","%s說:真不甘心呀!!人家還沒那個......!\n") ;
        wield_weapon( CAMPOBJ"blunt1" );
        equip_armor( CAMPOBJ"head1" );
        equip_armor( CAMPOBJ"suit1" );
        equip_armor( CAMPOBJ"cloak1" );
        equip_armor( CAMPOBJ"legging1" );        
        equip_armor( CAMPOBJ"boots1" );
}

int accept_item(object who,object item)
{
  int code;

  if ( !item->query_inked() ) {
    tell_room( environment(), 
      "露露微笑地說: 你給我一張白紙有何企圖？向我表白嗎？\n");
      command("give paper to "+who->query("name"));
      return 1; 
  }
  if ( (int)who->query_quest_level("lulu") >=1 ) code=1; else 
  if (who->query_temp("lulu_active")) code=3; else code=2 ; 
  if (code==3) 
  if (who->query_temp("lulu_mob2"))
     if (who->query_temp("lulu_mob3"))
        if (who->query_temp("lulu_mob4")) code = 4 ; 

  if (code==1)
     tell_room( environment(), 
        sprintf("露露向%s(%s)點頭微笑，說道: 謝謝！\n",
        who->query("c_name"),who->query("name") ), who ) ;

  if (code==3) 
    tell_object( who,"露露點頭微笑，說道: 謝謝！請再為我尋找我的將軍吧!!\n");

  if (code==4) { 
    who->delete_temp("lulu_active") ;
    who->delete_temp("lulu_mob2") ;
    who->delete_temp("lulu_mob3") ;
    who->delete_temp("lulu_mob4") ;
    who->finish_quest("lulu",1);
    tell_object( who, 
       "[你終於完成了 露露(lulu) 任務，得到 3000 點經驗]\n"
       );
    who ->gain_experience(3000);
    tell_object( who, 
       "露露說：為了感謝你的功德,我將教授你露營技巧,來快速恢復體力與法力!!\n"
       "        只要輸入 train camp 就可以了!!\n"
       );
   item->remove();
    return 1;
  }
  command("give paper to "+who->query("name"));
  return 1;
}

int check_trainee(object who)
{
   if( who->query_skill("camp") ) return 1;
   if( (int)who->query_quest_level("lulu") < 1 )
      return notify_fail(
      "露露說: 抱歉! 你還未完成我的任務!!\n" );
   if( (string)who->query("class")=="adventurer" &&
       (int)who->query_level()> 4 )
   return 1;
   else return notify_fail(
     "露露說: 我只教夠資格的冒險者啦!\n" );
}

void init()
{
	npc::init();
	teacher::init();
}
