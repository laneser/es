#include <mudlib.h>
#include <daemons.h>
#define COST_SP 2 
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
int life_time = 13;
string name;
string str1="火精靈說：我的朋友、我必須要走了，假如須要我幫忙請再叫我。\n";
string str2="你見到火精靈化成一團紅雲向天空飛去。\n";
string str3="HIR";

void create()
{
	::create();
	set_level(13);
	set_name( "fire spirit", "火精靈" );
	add( "id", ({ "spirit" }) );
	set_short( "火精靈" );
	set_long(
		"一個全身通紅冒著火焰頭上綁了個蝴蝶結的精靈。\n"
	);
	set( "unit", "個" );
	set( "race", "elf" );
	set( "alignment",  800 );
        set( "tactic", "flank");
	set( "tactic_func", "my_tactic" );
        set_c_verbs( ({"%s通紅的手臂突然暴長，抓向%s",
                       "%s用手一指，一點火花射向%s",
                       "%s的雙眼往%s射出兩道紅色的光芒"}) );
// 精靈不再會被攻擊，不需要這個了
//	set_skill( "dodge", 80 );
}

int environment_check()
{
  return 1;
}

// 這個也不需要了
/*
int receive_damage(int damage)
{
       int hits;
       object act_ob,master;

       master=(object)query_temp("master");
       hits = (int)master->query("hit_points");
       act_ob = previous_object();
       if( act_ob && living(act_ob) ) set("last_attacker", act_ob);
       if( damage <= 0 || link_data("dead") || hits < 1 || query("linkdead") )
                return 0;
       hits -= damage/2;
       master->set( "hit_points", hits );
       set( "hit_points", hits);
       seteuid(getuid());
       tell_object(master," ( 你"+(string)"/adm/daemons/statsd"->c_status_string(master)+" )\n");
       return 1;
}
*/
int my_action(object me)
{
	int life;
	object victim ;
 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	life = (int)me->query("spell_points")/COST_SP ;
	if (life < life_time ) 
		life_time = life ;
	this_object()->move(environment(me));
	tell_object(me,"火精靈對你說：沒問題...我馬上來幫你擊退敵人!\n");
	tell_object(me,set_color("突然晴天一聲霹靂，火精靈挾著雷霆之勢從天而降和你一起攻擊敵人。\n","HIR"));
	tell_room(environment(me),
	set_color("你見到"+me->query("c_name")+
	"念著一些咒語，突然晴天一聲霹靂，\n一隻火精靈挾著雷霆之勢從天而降對"+
	me->query("c_name")+"的敵人發動攻擊。\n","HIR"),me);
	victim = me->query_attacker();
        if (victim) {
	  kill_ob(victim);
// 加這行，精靈不在敵人攻擊目標之內，精靈永遠不會被打
	  victim->remove_attacker(this_object());
        }
        name=me->query("name");
        call_out("check_battle",1,me,this_object());
	return 1;
}

// 用delay的方式等gain_exp做完還是會有一些問題.
/*
void wait_get_exp(object me,object mob)
{
  END->bye_bye(me,mob,13,str1,str2,str3);
  return;
}
*/

void check_battle(object me,object mob)
{
  object tmp;
  if ((!mob)||(!me))
    return;
  if (!(tmp=find_living(name))||(tmp->query("npc"))) {
    tell_room(environment(mob),
      "火精靈在你的身後大叫：臭小子，居然給我QUIT掉了...\n"
      "說完也跟著消失了。\n");
    mob->remove();
    return;
  }
  else if (!me->query_attacker()) {
  //  直接消失即可 . player
  //  call_out("wait_get_exp",5,me,mob);
    END->bye_bye(me,mob,13,str1,str2,str3);
    return;
  }
  else if (!mob->query_attacker()) {
    END->bye_bye(me,mob,13,str1,str2,str3);
  }
  else if ( ! present(me,environment()) ) {
     END->bye_bye(me,mob,13,str1,str2,str3);
     return;
  }
  else
    call_out("check_battle",2,me,mob);
// 有定義一個參數 : life time，它是精靈所能為主人作戰的最大回合數
// 在每次 call my_tactic 時都會減一 ( 因為 my_tactic 每回合 call 一次)
// 這樣，只要檢查 life 就可以了，不一定要使用 call_out ...
// 不過我想你一定有你的考慮 ..
}

int my_tactic()
{
	object master,victim;
	int dam;
	
	master = (object)query_temp("master");
        if (!master) return 1;
        if ((int)master->query("spell_points")<0)
           return END->bye_bye(master,this_object(),13,str1,str2,str3);
	master->add("spell_points",-COST_SP);
	if ( life_time-- < 0 ) 
          return END->bye_bye(master,this_object(),13,str1,str2,str3);
/*	if ( ! present(master,environment()) ) {
	  tell_object(master,"火精靈在你的身後大叫：臭小子，丟下我烙跑？？你給我記志 ...\n");
	  tell_room(environment(),"火精靈叫道 : 哎啊 ! "+master->query("c_name")+"這個臭小子丟下我跑了？我也要溜了 ..\n");
	  if ( !wizardp(master) )
  	    END->can_summon_again(master,13);
	  else
	    master->delete_temp("summon_rest");
          this_object()->init_attack();
   remove();
	  return 0;
	}
*/
	if( !(victim = query_attacker()) ) return 0;
        this_object()->execute_attack(0);
	if( random(20)<2 ) {
           dam = 10 + 2*random(13);

// 加這行確保 mob 不會被精靈的特殊攻擊打死 ... 主人會得不到經驗
//           if ( (int)victim->query("hit_points") < dam ) return 0;
// 現在應該不會有這種問題了. player 

// set_color() 時，第三個參數為判斷顏色的對象，如果不設，就是這隻精靈
// 這就是為什麼有時候看不到顏色的原因，設成 master 即可 
	  tell_room( environment(this_object()),
	    set_color("\n火精靈把口一張，從嘴裡射出一團火焰攻擊敵人 !\n\n","HIR",master)
            , this_object()
	    );
          victim->receive_special_damage("fire", dam);
        }
        if (victim->query("last_attacker")==this_object())
          victim->set("last_attacker",master);
	return 1;
}

// 現在不會由spirit執行gain_experience()了
/*
int gain_experience(int exp)
{
	object master;
	if ( query_attacker() ) return 1;
	master = (object)this_object()->query_temp("master");
	if ( !present(master,environment()) ) {
		return END->bye_bye(master,this_object(),13,str1,str2,str3);
	}
	if ( master->query_temp("leader") ) 
		PARTY_D->share_experience(master,exp ) ;
	else {
			master->gain_experience(exp);
            tell_object(master,sprintf("你得到 %d 點經驗值。\n",exp));
 			}
 	return END->bye_bye(master,this_object(),13,str1,str2,str3);
}	
*/
