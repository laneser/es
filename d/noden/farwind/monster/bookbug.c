#include <mudlib.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(1);
        set_name( "bookbug", "肥肥的蛀書蟲" );
        add("id",({"bug"}) );
        set_short( "肥肥的蛀書蟲" );
        set_long(@LONG
一隻肥肥的小蟲，不仔細看還看不到，它正高興的啃著散落的書頁，
依你的經驗看起來，這麼弱小的蟲蟲，只要你一腳就可『踢』死它。
LONG
        );
        set( "gender", "male" );
        set( "race", "shapeshifter" );
        set( "alignment", -10 );
        set_natural_armor( 1, 2 );
        set_natural_weapon( 5 , 2 , 3 );
        set_perm_stat( "kar", 10 );
        set("exp_reward",1);
}
 
void init()
{
        add_action("to_kick","kick");
}
 
int to_kick(string str)
{
   object who, owner;
   
   who = this_player();
   owner = present( "book shop owner", environment(this_object()) );
   
   if (str != "bookbug" && str != "bug")
                return notify_fail( "你想踢啥?\n" );
   tell_object(this_player(),@LONG
你狠狠的往小蟲身上踹了下去，小蟲連掙扎的機會也沒有，就爛成一團死掉了。
LONG
        );
   if ( (int)who->query_quest_level("bookbug") > 0 ) {
        this_object()->remove();
        return 1;    
     }  
   if( !owner ) {
        this_object()->remove();
        return 1;
     }   
                   
   tell_object(who,@LONG
書店老闆感激的握著你的手說 :
謝謝你幫我殺死蛀蟲! 這下子我就不必擔心書會賣不出去啦!
真的是非常的感激!
 
你完成了『書店老闆的煩惱』的任務，獲得 300 點經驗點。
LONG
        );
  
//如果不是自己找或是踢的話 任務點數會比較少。
   if ( (int)who->query_temp("findbug") < 1 )   
        who->finish_quest( "bookbug", 1 );
      
   who->finish_quest( "bookbug",2 );
   who->gain_experience(300);
   who->delete_temp("findbug");
   this_object()->remove();
  return 1;
}
 
void die()
{
  object who, owner;
  who = query( "last_attacker" );
  owner = present( "book shop owner", environment(this_object()) );
  
  if ( !who->query_quest_level("bookbug") && owner ) {
        tell_object(who,@LONG
書店老闆感激的握著你的手說 :
謝謝你幫我殺死蛀蟲! 這下子我就不必擔心書會賣不出去啦!
真的是非常的感激!
 
你完成了『書店老闆的煩惱』的任務，獲得 300 點經驗點。
LONG
        );
     who->finish_quest( "bookbug", 1 );
     who->gain_experience(300);
  }
     
  ::die();
}
 
