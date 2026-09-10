#include "../legend.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "hostress", "女主人");
        set_short("女主人" );
	set_long(@C_LONG
女主人約莫四十多歲年紀，卻有沈魚落雁之貌，和男主人可說是天造地設的一雙。
在二十多年前，女主人是位轟動武林驚動萬教的人物，歷經了幾百場戰役，卻從未
被打敗過，堂堂擠身為一流高手之列。女主人自從與男主人相遇，一時被驚為天人
，如今卻心甘情願跟著男主人雙雙過著隱居的生活，一度令人極為詫異，卻因此佩
服她的勇氣。
C_LONG
	);
	set( "gender", "female" );
	set( "race", "human" );
	set( "alignment",100 );
	set( "time_to_heal", 7 );
	set_natural_armor( 70 , 30 );
	set_natural_weapon( 24 , 8 , 6);
	set("max_hp",700);
	set("hit_points",700);
        set("max_fp",500);
	set("force_points",500);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",25 );
	set_skill( "parry",80 );
	set_skill( "longblade",70);
	set("spouse","host");
	set( "wealth/silver",200);
	set( "special_defense", ([ "all": 45,"none":30 ]) );
	set( "aim_difficulty",(["critical":70,"vascular":60,"weakest":50]) );
	set("couple",1);
        equip_armor(LARMOR"moon_ring");
        equip_armor(LARMOR"moon_amulet");
        wield_weapon(LWEAPON"red_sle");                                              
        set( "tactic_func", "my_attack" );
        set("inquiry", ([
                "third":"@@ask_third",
                         
        ]) );
        set("scholar_gonfu/couples_sword",30);
        set("scholar_gonfu/han",30);
} 
void ask_third(object asker)
{
write(@C_LONG
女主人道：我相公要你來問我喔？那好吧，我給你一項工作，妾身近來皮膚老化，
　　　　　苦無良方可以回復以往面貌，希望你為我想個辦法。
C_LONG
      );
}
int accept_item(object me, object item)
{
   string pname,name;
   pname=me->query("name");
   name=item->query("name");
   if( name!="red fruit" ) {
      command("give "+name+" to "+pname);
      tell_object(me,"女主人道：咦，你給我這個東西是什麼啊？\n");
      return 1;
   }
   if( me->query_temp("third") ) {
      tell_object(me,@C_LONG
女主人說道：謝謝，我已經很年輕了。      
C_LONG
   );   
      command("give "+name+" to "+pname);
      return 1;
   }
   tell_object(me,@C_LONG
女主人吃下你帶給她的朱果，瞬間年輕了好幾十歲。哇！比「歐雷」還好用咩！

女主人感激地向你說謝謝 ^_^

C_LONG
    );     
    item->remove();
    me->set_temp("third",1);
    return 1;
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

   if( !victim =query_attacker() ) return 0;
   
   if( query("force_points") < 50 ) set("force_points",500);
                        
   couples = filter_array( all_inventory(environment(this_object())),
           "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) {
      tell_room( environment(this_object()), sprintf(
          "%s怒道:我們豈是那麼好欺負的,給我下地獄去吧!!\n",couples[i]->query("c_name"))
          ,couples[i]);
      couples[i]->kill_ob(victim);
   }
   if ( !present("host",environment(this_object())) ) {
        set("attack_skill","scholar/han");                                    
        delete_temp("extra_db");
   }
   else set("attack_skill","scholar/couples_sword");
   return 0;
}
