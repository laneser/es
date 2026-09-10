#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "chan", "全執祥" );
	add( "id",({"chan"}) );
	set_short( "全執祥" );
	set_long(@C_LONG
全執祥原是丐幫頗聰明的弟子,幾年前為了奪取幫主之位不惜糾結外人打擊丐幫。
所幸被幫主『喬峰』及時發現,並且廢了他的武功免去了幫中一大浩劫。全執祥現
在之所以被囚禁在這裡完全是念在他以前的功勞,不然早就回去蘇洲賣鴨蛋了。你
現在看到他真想把他狠狠的修理一頓。 
C_LONG	
        );
        set( "unit", "名" );
        set("hit_points",5000);
        set("max_hp",5000);
	set( "race","human");
	set( "gender", "male" );
	set( "alignment", -6000 );
	set( "wealth/gold", 10 );
        set("chat_chance",1);
        set_natural_armor(0,0);

        set("chat_output",({
          "全執祥說道:唉,真後悔我所犯的錯 ( mistake )。\n",
                                  }) );
        set("aim_difficulty",
          (["critical":120,"vascular":120,"weakest":120]) );
        set( "inquiry", ([
                  "mistake":"@@ask_mistake"
            ]) );
        set( "tactic_func", "cast_spell");
        
}

void ask_mistake(object asker)
{
   
   if ( ( !asker->query_temp("gonfu_asked") ) &&
        ( !asker->query_temp("jail_asked") ) ) {
      tell_object( asker,"全執祥說道:阿□陀佛。\n");  
      return ;
   }
   if ( this_object()->query("be_asked") )
     tell_object( asker,"全執祥說道:阿□陀佛。\n");
   else {
     tell_object( asker ,
        "全執祥說道:唉,我所犯的錯?\n"
        "全執祥深深地嘆了一口氣並且注視著天上回想以前的事。\n");
        call_out("recover1",10,asker);
        this_object()->set("be_asked",1);
        call_out("recover2",1800,this_object());
   }
}
void recover1( object asker )
{
   object ob1;
   
   tell_object( asker ,
      "全執祥嘆道:十多年以前,我因為利慾薰心想謀取幫主之位,不惜借外人之力打擊\n"
      "           本幫以至於本幫弟子損傷慘重,精英頓遭浩劫,幫主卻念在我以往的\n"
      "           苦勞份上免我一死。唉,我雖萬死亦不足以惜一。 那我現在只有一\n" 
      "           個願望;就是想見見我那兒子,可是枷牢萬鎖想必是不可能了。我這\n"
      "           裡有一封信,請你轉交給我的兒子。大恩不言謝,阿彌陀佛\n"
      ); 
   ob1=new(DITEM"chan_letter.c");
   ob1->set("master",asker->query("name"));
   ob1->move(this_object());
   command("give chan letter to "+asker->query("name"));
} 
void recover2( object obj )
{
    obj->delete("be_asked");
}
int cast_spell()
{
    object victim;
      
       victim = query_attacker();
       if( !victim ) return 0;
       if ( ( random(10)>6 ) ){
          tell_room(environment(this_object()),
             "全執祥從口袋中拿出創藥吃吃......\n\n");
          this_object()->receive_healing(200);        
          victim->receive_damage(10);
          return 1;
       } return 0;   
}