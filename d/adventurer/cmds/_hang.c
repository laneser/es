//#pragma save_binary

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include <daemons.h>

inherit DAEMON;


int help();
int hang_work(object me, object target,object weapon);
int cmd_hang(string arg)
{
	object target,weapon,me;
	int num,sp_cost,level,skill;
	
	me = this_player();
	
	if( me->query_level() < 5 )
	        return notify_fail("你到底想幹嘛啦?\n");
	if( me->query_temp("hang_busy") )
	        return notify_fail("你正專心的作其他的事。\n");
	if ( ! arg ) {
	     if (!me->query("adventurer_exp/hang")) write("你目前對絞殺一竅不通...\n");
	     write("你目前對絞殺這件事的熟練度已經有"+me->query("adventurer_exp/hang")+"點了...\n");
	     return 1;
	     }
	if ( !(target = present( arg,environment(this_player()))) )
		return notify_fail("這裡沒有叫"+arg+"的東西。\n");
	if ( target == this_player() )
		return notify_fail("你把自己高高的掛在一棵樹上....\n");
	if ( ! living(target) ) 
		return notify_fail("你用力的勒住"
			+target->query("c_name")+"但是什麼事也沒發生。\n");
	if ( !visible(target,this_player()) || target->query("invisible_player") )
		return notify_fail("你想絞殺誰?\n");
	if ( !this_player()->query_vision() )
		return notify_fail("這裡一片漆黑 ! 你什麼也看不到 !!\n");
	if( !skill = (int)me->query_skill("hang") )
	                return notify_fail( "你沒有學過絞殺技巧!!無法絞殺!!\n");
	if ( target->query("no_attack") ) {
	        write("這傢伙－不能殺。\n");
	        return 1;
	}
	if ( userp(target) ) {
		if ( (int)target->query_level()< 5 || 
			 (int)this_player()->query_level()<5 )
		return notify_fail("你不能 PK 他 !!\n");
	}
	weapon = this_player()->query("weapon1");
	if ( !weapon )
		return notify_fail("你沒有武器，無法絞殺敵人 !!\n");	
	if ( (string)weapon->query("type") != "whip" )
		return notify_fail("你的武器不趁手，無法絞殺 !!\n");
        level = me->query_level();
        skill = me->query_skill("hang");
        num = me->query("adventurer_exp/hang")/2500;
        sp_cost = 180 - level*2 - skill - num ;
	if( sp_cost < 30 ) sp_cost = 30;
	
	if( !sp_cost || (int)me->query("spell_points") < (sp_cost + 1) )
		return notify_fail("你的精神太差了，無法專心進行絞殺！\n");

   	if( !me->query_attackers() ) {
   	tell_object( me, set_color( 
		"你偷偷摸摸的繞到" + target->query("c_name") + "後，準備隨時給它一個絞殺..\n\n", "HIY",me) );
		
	tell_object(target, set_color( 
		me->query("c_name")+"偷偷走到你後面，不知道要幹什麼?\n\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"偷偷摸摸的繞到"+
		target->query("c_name")+"的身後，不知道要幹什麼?\n\n" ,
		({ me, target }) );
        me->add("spell_points",-sp_cost);
        me->set_temp("hang_busy",1);
                call_out("hang_work", 4, me, target, weapon);
                return 1;
                       }
        write("你正忙於戰鬥，不能分心去作別的事情....\n");
                return 1;
}

int hang_work(object me, object target, object weapon)
{
   int i,dam,dam1,skill1,skill2,my_str,wc,explore,total_points,EXPLORE1,time;
   object *who_fight;
   
   time = target->query_temp("hang_time");
   who_fight = (object *)target->query_attackers();
   me->delete_temp("hang_busy");
   wc = weapon->query("weapon_class")/2;
   explore  = (int)this_player()->query_explore_points();
   total_points=EXPLORE_D->query_total_explore();
   EXPLORE1=explore*40/total_points;
   if (EXPLORE1 > 40) EXPLORE1 = 40;
   skill1 = me->query_skill("hang");
   skill2 = me->query_skill("anatomlogy");
   my_str = me->query_stat("str");
   dam1 = my_str - 2*(int)target->query_stat("con") + skill2 + wc + EXPLORE1 ;
   dam = dam1*2/5  ;
   if (dam < 15) dam = 15; 
  
   if ( !present(target,environment(me)) ) {
   tell_object( me, set_color(
            "咦! 你突然發現你的目標不見了?\n" , "HIY",me) );
   return 1;
   }                  
  
   //這是為了防玩家用do 指令出去再進來絞殺怪物，所以不能在一開始的地方check
   //詳情請見/std/npc2.c    Takeda@ES  
   
      for( i=sizeof(who_fight)-1; i>=0; i-- ) {
      if ( who_fight[i]->query("name") == me->query("name") ) {
      
      tell_object( me, set_color(
               "你用你手中的"+ weapon->query("c_name")+ "往" + target->query("c_name")+"脖子揮去\n"
               "沒想到他隨隨便便就閃過了....，你用力過猛摔倒在地\n" , "HIY",me) );
   
      tell_object(target, set_color("\n"+
         me->query("c_name")+"想要用"+weapon->query("c_name")+"絞殺你，不料卻自己摔倒在地。\n", "HIM",target));
 
      tell_room( environment(me), "\n"+
                   me->query("c_name")+"將手中的"+weapon->query("c_name")+"揮向"+target->query("c_name")+"的脖子，但是\n"
                   "不但沒套中目標，自己反而踩到鞭子跌倒。\n\n" ,
                    ({ me, target }) );   
   me->kill_ob(target);
   me->block_attack(2);
   me->set_temp("msg_stop_attack", "（ 你現在摔倒在地無法動彈 ）\n\n");
   return 1;
   }
   else continue ;
   }
   
   
   if ( random(skill1/3) + skill2/3 + wc + random(EXPLORE1)/4 - 2*(int)target->query_stat("dex") - random(time) < 0) {
      tell_object( me, set_color( 
		"你用你手中的"+ weapon->query("c_name")+ "往" + target->query("c_name")+"脖子揮去，"
		"可惜被他閃過了....\n\n" , "HIY",me) );
	tell_object(target, set_color("\n"+ 
		me->query("c_name")+"想要用"+weapon->query("c_name")+"絞殺你，還好你閃開了。\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"將手中的"+weapon->query("c_name")+"揮向"+
		target->query("c_name")+"的脖子，但是沒套中目標。\n\n" ,
		({ me, target }) );
                
                target->kill_ob(me);
                me->block_attack(2);
                me->set_temp("msg_stop_attack", "（ 你現在手忙腳亂無法攻擊 ）\n\n");
                return 1;
       }
   	tell_object( me, set_color( 
		"你成功用手中的" + weapon->query("c_name") + "絞殺" + target->query("c_name") +
		"，使他受到嚴重的傷害。\n\n", "HIY",me) );
		
	tell_object(target, set_color( "\n" +
		me->query("c_name")+ "用手中的" + weapon->query("c_name") + "纏住你的脖子。\n"
		"你感覺到一種窒息般的痛苦。\n\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"用手中的"+ weapon->query("c_name") + "纏住" +
		target->query("c_name")+"的脖子，使得他露出非常痛苦的表情。\n\n" ,
		({ me, target }) );
   target->kill_ob(me);
   target->block_attack(5);
   target->add_temp("hang_time",1);
   target->set_temp("msg_stop_attack", "（ 你剛才被"+me->query("c_name")+"絞殺，痛苦仍未恢復，無法攻擊...\n\n");
   target->receive_damage( dam );
   target->set("last_attacker", me );
   (CONDITION_PREFIX + "weak")->apply_effect( target, 2, 10 );
   me->add("adventurer_exp/hang",(int)dam/2 + target->query_level());
   return 1;
}
int help()
{
    write(
@C_LONG
指令格式: hang + <指定對象>
若不加對象則為查詢你對絞殺的熟練度

使用鞭類武器時，冒險者有能力絞殺毫無戒心的敵人。
若施術成功，受術者不但本身受到傷害，且力量會暫時性大量
下降，且若干回合無法任意行動，而施術者為維持絞殺的效果，
則需花費大量的精神力以控制對方的行動。
C_LONG
    );
    return 1;
}    
