//#pragma save_binary

#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit DAEMON;


int help();
int hang_work(object me, object target,object weapon);
int cmd_hang(string arg)
{
	object target,weapon,me,*who_fight;
	int sp_cost,level,skill;
	
	me = this_player();
	
	if( me->query_level() < 5 )
	        return notify_fail("你到底想幹嘛啦?\n");
	if( me->query_temp("hang_busy") )
	        return notify_fail("你正專心的作其他的事?\n");
	if ( ! arg ) return notify_fail("你想絞殺誰?\n");
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
	        write("這傢伙－－－不能殺。\n");
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
        who_fight = (object *)target->query_attacker("who_protect");
        level = me->query_level();
        skill = me->query_skill("hang");
        sp_cost = 180 - level*2 - skill;
	
	if( !sp_cost || (int)me->query("spell_points") < (sp_cost + 1) )
		return notify_fail("你的精神太差了，無法專心進行絞殺！\n");
        if( !me->query_attacker(); ) { 

   	tell_object( me, set_color( 
		"你偷偷摸摸的繞到" + target->query("c_name") + "後，準備隨時給它一個絞殺..\n\n", "HIY",me) );
		
	tell_object(target, set_color( 
		me->query("c_name")+"偷偷走到你後面，不知道要幹什麼?\n\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"偷偷摸摸的繞到"+
		target->query("c_name")+"的身後，不知道要幹什麼?\n\n" ,
		({ me, target }) );
        me->set("spell_points",(int)me->query("spell_points")-sp_cost);
        me->set_temp("hang_busy",1);
                call_out("hang_work", 3, me, target, weapon);
                return 1;
                       }
        write("你正忙於戰鬥，不能分心去作別的事情....\n");
                return 1;
}

int hang_work(object me, object target, object weapon)
{
   int dam,skill1,skill2,my_str,my_kar,wc;
   
   me->delete_temp("hang_busy");
   wc = weapon->query("weapon_class")/2;
   skill1 = me->query_skill("hang");
   skill2 = me->query_skill("anatomlogy");
   my_str = me->query_stat("str");
   my_kar = me->query_stat("kar");
   dam = my_str + my_kar - 3*(int)target->query_stat("dex") + skill2/2 + wc;
   if (dam < 10) dam = 10; 
   if (dam > 30) dam = 30;
   if (skill1/3 + skill2/5 + wc + random(my_kar) - 2*(int)target->query_stat("dex") < 0) {
      tell_object( me, set_color( 
		"\n 你用你手中的"+ weapon->query("c_name")+ "往" + target->query("c_name")+"脖子揮去\n"
		"可惜被他閃過了....\n\n" , "HIY",me) );
	tell_object(target, set_color("\n"+ 
		me->query("c_name")+"想要用"+weapon->query("c_name")+"絞殺你，還好你閃開了。\n", "HIM",target));

	tell_room( environment(me), "\n"+
		me->query("c_name")+"將手中的"+weapon->query("c_name")+"揮向"+
		target->query("c_name")+"的脖子，但是沒套中目標。\n\n" ,
		({ me, target }) );
                me->set("stop_attack",2);
                target->kill_ob(me);
                me->kill_ob(target);
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
   target->set("stop_attack",4);
   target->receive_damage( dam );
   target->set("last_attacker", me );
   (CONDITION_PREFIX + "weak")->apply_effect( target, 2, 12 );
   target->kill_ob(me);
   me->kill_ob(target);
   return 1;
}
int help()
{
    write(
@C_LONG
指令格式: hang + <指定對象>

使用鞭類武器時，冒險者有能力絞殺毫無戒心的敵人。
若施術成功，受術者不但本身受到傷害，且力量及敏捷均暫時性
下降，且若干回合無法任意行動，而施術者為維持絞殺的效果，
則需花費大量的精神力以控制對方的行動。
C_LONG
    );
    return 1;
}    
