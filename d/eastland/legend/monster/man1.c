#include "../legend.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "host", "男主人");
        set_short("男主人" );
	set_long(@C_LONG
男主人是一位俊美挺拔，風度翩翩的中年人，他的四肢百駭散發出一股仙氣，全身
上下似乎被籠罩在一團暮靄裡，這樣的一位仙風道骨，使你不禁地想親近他。在三
十多年前，男主人原本是一位江湖中頗負盛名的劍客，卻在到達巔峰之際急流湧退
，一時令許多人錯愕，並且佩服他的勇氣。他現在處於隱居狀態，但手上工夫依然
不弱喲，你可以跟他請教劍法，相信他會很樂意教你的。
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment",100 );
	set( "time_to_heal", 7 );
	set_natural_armor( 70 , 35 );
	set_natural_weapon( 34 , 13 , 13);
	set("max_hp",700);
	set("hit_points",700);
        set("max_fp",500);  
	set("force_points",500);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",25 );
	set_skill( "parry",80 );
	set_skill( "longblade",100);
	set("spouse","Hostress");
	set( "wealth/silver",200);
	set( "special_defense", ([ "all": 45, "none":30 ]) );
	set( "aim_difficulty",(["critical":70,"vascular":60,"weakest":50]) );
	set("couple",1);
        equip_armor(LARMOR"sun_ring");
        equip_armor(LARMOR"sun_amulet");
        wield_weapon(LWEAPON"phenix1");                                              
        set( "tactic_func", "my_attack" );
        set("inquiry", ([
                 "sword":"@@ask_sword",
                  "劍法":"@@ask_sword",
                 "first":"@@ask_first",
                 "second":"@@ask_second",
                 "third":"@@ask_third",
        ]) );
        set("scholar_gonfu/couples_sword",30);
        set("scholar_gonfu/han",30);
} 
void init()
{
   ::init();
   add_action("do_say","報告");
}
void ask_sword(object asker)
{
write(@C_LONG
男主人道：嗯，我夫婦兩縱橫江湖二十年，打敗高手無數，惟恨遍訪無人能傳我畢
　　　　　身絕學，如果你想做為我夫婦的徙弟，那你必須完成我給你的三件事。
         ( first second & third)
C_LONG
      );
}
void ask_first(object asker)
{
write(@C_LONG
男主人道：第一件事：
　　　　　我以前的朋友「丐幫幫主　震八方」寄了封信給我希望我夫婦前去助他
　　　　　一臂之力，但因久未涉江湖，不知如何是好，既然你有心要成為我們的
　　　　　徒弟，那你就替我們幫他解決困擾，這樣算是完成第一件工作。
C_LONG
      );
}
void ask_second(object asker)
{
write(@C_LONG
男主人道：第二件事：
          在此前去東五十里有個漁村，漁村裡有需要幫助的人，你快去幫助他，
          他是我以前的恩人。喔，忘了告訴你，他是漁村的村長，而這是第二件
          工作。
C_LONG
      );
}
void ask_third(object asker)
{
write(@C_LONG
男主人道：第三件事：
          問我夫人吧。如果你完成了三件事，向我「報告 男主人」就可以了。
C_LONG
      );
}
int do_say(string arg)
{
   object me;
   if ( !arg || arg!="男主人" )
      return notify_fail("你要向誰報告?\n");
   me=this_player();
//      if( me->query_quest_level("couples") ) {
   if ( me->query("couples") ) {
      tell_object( me,"男主人說道：乖徒弟，你找為師的有什麼重要的事情嗎？\n");
      return 1;
   }
//   if ( !( (me->query_quest_level("dony1"))&&
   if( !( (me->query("finish_dony")) &&
          (me->query_temp("second")) &&
          (me->query_temp("third") )    ) )  {
       tell_object( me,"男主人說道：再加把勁吧！\n");      
      return 1;             
   }          
//   me->finish_quest("couples", 1);
    me->delete_temp("second");
    me->delete_temp("third");
    me->set("couples",1);
    me->gain_experience(8000);
    tell_object( me,@C_LONG 
男主人道：好孩子，你終於不負所望完成我交待給你的三件工作。好，我就收你
　　　　　為徒吧！
         
      
      [你獲得男主人的賞賜得到 8000 點經驗]\n\n");

C_LONG
    ); 
     me->delete("blind");
     me->set("medication_resistance",0);
     if ( me->query("class")!="scholar" ) {
        tell_object( me,@C_LONG
男主人繼道：唉，本來為師想傳你一套劍法，但因你骨骼不佳，資質不夠。也就作
　　　　　　罷了。
無論你百般地哀懇，男主人就是不傳你劍法，你不禁傷心地嘆了一口氣。     
C_LONG             
     ); 
     return 1;
     }
     tell_object( me,@C_LONG
男主人摸了摸你全身的骨骼．．
男主人很滿意地道：不錯，你資質奇佳，足以學我夫婦倆縱橫江湖十多年的劍法。

只見男主人雜七雜八地說了幾句話，你卻一點也不懂他在講什麼．．．．
男主人看見你充滿疑問的表情，憤怒地道：什麼，你連一句話也都沒有記得，回公
　　　會好好想想(ponder)清楚吧！
C_LONG
     );
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
          "%s怒道:我們豈是那麼好欺負的,給我下地獄去吧!!\n",couples[i]->query("c_name")),
          couples[i]);
      couples[i]->kill_ob(victim);
   }
   if ( !present("hostress",environment(this_object())) ) {
        set("attack_skill","scholar/han");                                    
        delete_temp("extra_db");
   }
   else set("attack_skill","scholar/couples_sword");
   return 0;
}
