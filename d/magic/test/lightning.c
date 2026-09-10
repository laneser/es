// This is a spell object, damage type -> electric.
// level    0    1    2    3    4    5
// cost    20   40   60   80  100  150
// damage  25   50   75  100  125  120
// type   one  one  one  one  one  all
// delay    1    2    2    3    3    4
// skill   50   60   70   80   90  100
// miss    20   40   60   80  100    ? % when target 100
// G_LVL    5   10   17   26   37   50
// G_EXP    3   10   20   32   50   70
// found by monster rate = monster(int*2+kar) - killer(int) / 70
// found by player rate  = victim(int+kar) - killer(int) / 70
// remark L3-L5 must be outside!
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "black-magic"

inherit DAEMON;

#define find_rate 70

int query_need_spell_level(int level)
{
	switch( level ) {
		case 0 : return  5;
		case 1 : return 10;
		case 2 : return 17;
		case 3 : return 26;
		case 4 : return 37;
		case 5 : return 50;
		default : return 99;
	}
}

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  3;
		case 1 : return 10;
		case 2 : return 20;
		case 3 : return 32;
		case 4 : return 50;
		case 5 : return 70;
		default : return 0;
	}
}

int query_need_skill(int level) { return 50+10*level; }

int query_sp_cost(object caster, int level, string target) 
{
  int sp;
  switch( level ) {
    case 1 : sp =  40; break;
    case 2 : sp =  60; break;
    case 3 : sp =  80; break;
    case 4 : sp = 100; break;
    case 5 : sp = 150; break;
   default : sp =  20; break;  }
   return modify_sp_cost(caster, sp, TYPE, query_need_spell_level(level));
}

int query_damage( object caster, int level )
{
  int dam;
  switch( level ) {
    case 1 : dam =  50; break;
    case 2 : dam =  75; break;
    case 3 : dam = 100; break;
    case 4 : dam = 125; break;
    case 5 : dam = 120; break;
   default : dam =  25; break;  }
   return modify_damage(caster, dam, TYPE, query_need_spell_level(level));
}

int query_delay_time( int level )
{
  switch( level ) {
    case 1 : return 2;
    case 2 : return 2;
    case 3 : return 3;
    case 4 : return 3;
    case 5 : return 4;
   default : return 1;  }
}

string query_effect_func( int level )
{
  if( level < 5 )
    return "effect_one";
  else
    return "effect_all";
}

int query_find_rate(object caster, object victim)
{
  if( !userp(victim) )
    return (int)victim->query_stat("int")*2 -
           (int)caster->query_stat("int") +
           modify_find_rate(caster)+
           (int)victim->query_stat("kar");
  else
    return (int)victim->query_stat("int") -
           (int)caster->query_stat("int") +
           (int)victim->query_stat("kar");
}

int cast(int level, string target)
{
	int delay_time;
	object me, targ;

	me = this_player();
	
	if( (int)me->query_skill("black-magic") < query_need_skill(level) ) {
	  tell_object( me, "你的黑魔法技能不足以使用這等級的魔法! \n"
      );
      return 0;
    }
	
	if( target=="NONE" && !(targ = me->query_attacker()) ) { 
		write( "要對誰施展雷殛術？\n");
	    return 0;
	} else {
		if( !targ ) 
			targ = present( target, environment(me) );
		if( !targ ) {
		   write( "你的目標並不在這裡！\n" );
	       return 0;
	    }
	}

	if( !living(targ) ) {
	    write( "雷殛術的目標必須是生物！\n" );
        return 0;
    }
	if( targ->query("no_attack") ) {
	    write( "不—可—以。\n" );
	    return 0;
	}
	if( targ==me ) {
	    write( "這 .... 不太好吧。\n" );
        return 0;
    }
    if( !check_level( me, targ, 1 ) ) return 0;
	write( "你開始念起雷殛咒文: 拉·依古瑪·得拉哈坦....。\n" );
	tell_room( environment(me), me->query("c_name") + "開始喃喃自語。\n" ,
		me);
	if( (!environment(me)->query("outside")) && (level>2) )
		tell_room( environment(me), "但是什麼事也沒有發生....。\n" );
	else {
	    if( !targ->query_attackers() &&
	       (random(find_rate)<query_find_rate(me,targ)) ) {
	      tell_object( me, targ->query("c_name")+
	        "發現你對他不懷好意而開始攻擊你。\n" );
	      tell_room( environment(targ), 
	        targ->query("c_name")+"發現"+me->query("c_name")+
	        "對他不懷好意而發動攻擊。\n", me
	      );
	      targ->kill_ob(me);
	      me->block_attack(2);
	    }
	    me->set_temp("cast_busy",1);
	    me->block_attack(query_delay_time(level)*2);
	    me->set_temp("msg_stop_attack", 
 	            "( 你正在施法，無法攻擊。 )\n"  );
 	    if( me->query("npc") && me->query("magic_delay") )
 	    	delay_time = (int)me->query("magic_delay")*2;
 	    else
 	    	delay_time = query_delay_time(level)*2;
		call_out( "pre_effect", 1, me, level );
		call_out( query_effect_func(level), delay_time, level, me, targ );
	}
	return 1;
}

void pre_effect( object caster, int level )
{
   if( level < 3 ) {
     tell_object( caster, "你的手中開始凝聚大氣中游離的電氣！\n" );
	 tell_room( environment(caster), 
	   sprintf("%s的手中開始凝聚大氣中游離的電氣！他的手中隱約的"+
	    "閃著幾團電光。\n",caster->query("c_name")), caster
	 );
   } else
     tell_room( environment(caster),
       "突然間天空中烏雲密佈，隱約可聽到幾聲沈悶的雷聲，由遠而近....。\n" );
}

void effect_one(int level, object caster, object victim)
{
	int damage;
	
    caster->set_temp("cast_busy",0);
    damage = query_damage(caster, level);
	damage += random((int)caster->query_stat("int"));
    recharging( caster, damage, "electric" );
    
	if( !victim || !present(victim, environment(caster)) ) {
	  if( level < 3 ) {
	    tell_object( caster, can_read_chinese(caster) ?
		  "你將手中的閃電箭往前一射，一條閃光呼嘯而過，消失在空中！\n":
		  "You shoot the lightning bolt.\n"+
		  "A flash goes through the sky and disappears.\n"
		);
	    tell_room( environment(caster), 
	      sprintf("%s將手中的閃電箭往前一射，一條閃光呼嘯而過，消失在空中！\n",
	      caster->query("c_name")), caster );
	  } else
		tell_room( environment(caster), 
		  "一道閃電從天而降擊中地面，轟出一個大洞....。\n" );
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
      return ;
    }
    if( !success_hit( 20+level*20, caster, TYPE, query_need_spell_level(level) ) ) {
      tell_object( caster, can_read_chinese(caster) ?
		sprintf("你手往前%s一指，一條閃光呼嘯而過，可惜沒打中！\n",
		victim->query("c_name") ) :
		"A flash goes through the sky but does not hit any body.\n"
      );
	  tell_room( environment(caster), 
	    sprintf("%s將手往前一指，一條閃光呼嘯而過，不過沒擊中任何人！\n",
	      caster->query("c_name") ), caster );
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
	  return;
    }
// hit effect ....
    if( level < 3 ) {
	  tell_object( caster, 
		sprintf(bold("你將手中的閃電箭往%s一射，一條閃光呼嘯而過，擊中他的身體！\n",caster),
		 victim->query("c_name") ) );

      tell_object( victim, can_read_chinese(victim) ?
		sprintf("%s將手中的閃電箭往你一射，你只見眼前白光一閃，隨即感到一陣劇痛！\n",
		 caster->query("c_name") ) :
		sprintf("%s shoot the lightning bolt at you.\n"+
		 "A flash goes through the sky and hits your body.\n",
		 caster->query("cap_name") )
      );
	  tell_room( environment(caster), 
	    sprintf("%s將手中的閃電箭往%s一射，一條閃光呼嘯而過，擊中他的身體！\n",
	     caster->query("c_name"), victim->query("c_name")) ,
	     ({caster,victim}) );
    } else {
	  tell_room( environment(caster), 
		sprintf( "一道閃電從天而降，只聽見「轟隆」一聲巨響，打在%s頭上！\n",
			victim->query("c_name") ) ,
		victim
	  );
	  tell_object( victim,
	    sprintf( bold(
		"突然，你只見眼前眩目的白光一閃，腦中短暫的空白之後，隨即感到一陣劇痛！\n",victim
		)));
	}

	damage -= random((int)victim->query_stat("int"));
	if( damage < 0 ) damage = 1;
	victim->kill_ob(caster);
	caster->kill_ob(victim);
	caster->gain_experience(damage);
	gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
	victim->receive_special_damage( "electric", damage, 0 );
	victim->set("last_attacker", caster);
	report( caster, victim );
}

int is_a_victim( object obj )
{
    if( living(obj) ) return 1;
}

void effect_all(int level, object caster, object targ)
{
    int i, damage;
    object *victim;
    caster->set_temp("cast_busy",0);
    gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
    damage = query_damage(caster, level);
    damage += random( (int)caster->query("int") );
    recharging( caster, damage, "electric" );
    
    tell_room( environment(caster), 
      "突然，只聽見「轟隆」之聲不絕於耳，無數的閃電自天而降，\n" );
    tell_object( caster, can_read_chinese(caster) ?
      "不過全部都打在你的旁邊。\n" : "But hit beside you terribly!\n" 
    );
    tell_room( environment(caster), 
	  "你只見眼前眩目的白光一閃，腦中短暫的空白之後，隨即感到一陣劇痛！\n", 
	  caster );
	victim = filter_array( all_inventory( environment(caster) ),
	         "is_a_victim", this_object() );
	if( sizeof(victim) ) {
	  i = sizeof(victim);
	  while( i-- )
	    if( (victim[i]!=caster) && !(victim[i]->query("no_attack")) &&
	        check_level( caster, victim[i], 0 ) ) {
	      damage -= random( (int)victim[i]->query("int") );
	      if( damage < 0 ) damage = 1;
	      victim[i]->kill_ob(caster);
	      caster->kill_ob(victim[i]);
	      victim[i]->receive_special_damage( "electric", damage, 0);
	      victim[i]->set("last_attacker", caster);
	      report(caster, victim[i]);
	    }
	}
}
