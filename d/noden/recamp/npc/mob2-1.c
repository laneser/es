#include <mudlib.h>
#include "../camp.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "sea general", "海冥將軍" );
	add("id",({"sea","general"}));
	set_short( "海冥將軍" );
	set_long(
         "海冥將軍有著一頭綠色的頭髮，相傳是海神的後裔，相當孔武有力。\n"
	);
	set( "alignment", 2000 );
	set_perm_stat( "dex", 10 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "str", 30 );
        set("race","orc") ;
        set("gender","male") ;
        set("max_hp",600) ;
        set("hit_points",600) ;
	set( "tactic_func", "my_tactic" );

        set_natural_armor(30,30);
        set_natural_weapon(30,10,30);
        set("aim_difficulty",
            (["critical":60,"vascular":50,"weakest":70,"ganglion":80])) ;
        set("wealth/silver",1000) ;
        set("weight",90) ;
        set_skill("dodge",80) ;
        set_skill("parry",80) ;

        wield_weapon(CAMPOBJ"3xgi2") ;
        equip_armor(CAMPOBJ"plate2") ;
}

int my_tactic()
{
    object victim;

    if( random(40)>10 || !(victim= query_attacker()) ) return 0;
      tell_object(victim,
          "\n將軍口中念動咒語，你看到一波海浪向你襲捲而來.\n"
          );
      tell_room(environment(victim),
          "\n將軍口中念動咒語，你看到一波海浪向"
          +victim->query("c_name")+"襲捲而去.\n"
          ,victim);
      victim->receive_special_damage("evil",40+random(10));
      "/d/magic/magic"->report(this_object(),victim);
      return 1;
}

int accept_item(object who,object item)
{
  if ( !item->query_inked() ) return 1 ;
  if ( (int)who->query_quest_level("lulu") >= 1 ) return 1 ;
  if (!(who->query_temp("lulu_active"))) return 1 ;  

  command("give paper to "+who->query("name"));
  if ( (who->query_temp("lulu_mob3")) && (who->query_temp("lulu_mob4")) )  
        tell_object( who,"說道: 謝謝！請把他交給露露吧!!\n");
  else  tell_object( who,"說道: 謝謝！請再尋找其他將軍吧!!\n");

  return 1;
}
