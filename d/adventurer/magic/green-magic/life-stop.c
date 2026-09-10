//This is a green-magic spell for adventurer casting only 
// Made by Takeda 11.8.1995////#pragma save_binary

#include <mudlib.h>
#include "/d/adventurer/magic/adm/magic.c"


#define TYPE "green-magic"
#define find_rate 50

int query_sp_cost(object caster, int level, string target) {return 20 + level * 20; }

int query_need_skill(int level) { return 10+30*level; }

int modify_find_rate(object caster)
{
   if ( caster->query("player_invisible") )
      return (int)caster->query_level()/2;
      return 0;
}
int query_find_rate(object caster, object dest)
{
  if( !userp(dest) )
      return (int)dest->query_stat("int")*2 -
      (int)caster->query_stat("int") +
      modify_find_rate(caster)+
      (int)dest->query_stat("kar");
else
      return (int)dest->query_stat("int") -
      (int)caster->query_stat("int") +
      (int)dest->query_stat("kar");
}

int cast(int level, string target)
{
	int chinese_mode, delay_time;
	object me, dest;

    me = this_player();
	chinese_mode = can_read_chinese(me);
	
	if( (int)me->query_skill("green-magic") < query_need_skill(level) ) {
		tell_object(me,set_color("你的綠魔法技能不足以使用這等級的魔法!\n","HIG"));
		return 0;
	}
	
	  if( target=="NONE" && !(dest = me->query_attacker()) ) {
	  write( "要對誰施展機能停止術？\n");
	  return 0;
	  } else {
	  if( !dest ) 
	  dest = present( target, environment(me) );
	  if( !dest ) {
	         write("你的目標並不在這裡！\n");
	         return 0;
	              }}                                       
	    if( !living(dest) ) {
	              write( "機能停止術的目標必須是生物！\n");
	                    return 0;
	                        }
	          if( dest->query("no_attack") ) {
	                    write("這傢伙不能殺。\n");
	                    return 0;
	                    }
	          if( dest==me ) {
	                    write("你可以打suicide 比較好。\n");
	                    return 0; 
	                    } 
	          if( dest->query_level()<5 ) {
	                    write("新手會說你沒有人情味...\n");
	                    return 0;
	                    }                       
	if( me->query("npc") && me->query("magic_delay") )
	    delay_time = (int)me->query("magic_delay");
	else
	    delay_time = 3;
	me->set("stop_attack",delay_time);
	me->set_temp("cast_busy", 1);
	tell_object(me,set_color("你開始吟誦綠魔法中機能停止術的咒文....。\n","HIG",me));
	tell_room( environment(me),
		me->query("c_name") + "開始吟誦綠魔法中機能停止術的咒文....。\n",
		me );
	call_out( "effect", delay_time, level, me, dest );
	if( !dest->query_attackers() &&
	        (random(find_rate)<query_find_rate(me,dest)) ) {
	        tell_object( me, dest->query("c_name")+
                "發現你對他不懷好意而開始攻擊你。\n" );
	tell_room( environment(dest),
	        dest->query("c_name")+"發現"+me->query("c_name")+
	        "對他不懷好意而發動攻擊。\n", me
	        );
	        dest->kill_ob(me);
	        me->kill_ob(dest);
	return 1;
	}
	return 1;
}

void effect(int level, object caster, object dest)
{
	int power,duration;

	caster->set_temp("cast_busy", 0);
	
	if( !dest ) {
	      tell_object( caster,"你發現你的目標已經死了。\n");
	      return;
	            }
	if( !dest || !present(dest, environment(caster)) ) {
	      tell_object( caster,"你發現你的目標已經離開這裡了。\n");
	      return;
	            }
	tell_room( environment(dest),
		"一些暗紅色的光氣從"+dest->query("c_name")+"身上升起，然後逐漸消失。\n",
		dest );
	tell_object( dest,"你突然有一種奇怪的感覺，好像是突然失去了所有的生命力\n",dest );	
		dest->set_temp("stop_heal_hp",1);
		dest->set_temp("stop_heal_tp",1);
		dest->set_temp("stop_heal_sp",1);
		duration = (level+1) * 20 + (int)caster->query_stat("pie") * 4;
		dest->kill_ob(caster);
		caster->kill_ob(dest);
		call_out( "expire", duration, dest);
	}

void expire( object dest )
{
    if( !dest ) return;
	tell_object( dest,
		"你覺得全身一陣舒暢，身體各部好像又開始運作起來..。\n"
    );
                 dest->set_temp("stop_heal_hp",0);
                 dest->set_temp("stop_heal_tp",0);
                 dest->set_temp("stop_heal_sp",0);
}
