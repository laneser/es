// This is a spell object, damage type -> none.
// level    0    1    2    3
// cost    40   80  120  200
// damage  40   90  140  180
// type   one  one  one  all
// delay    2    2    3    4
// skill   80   90   95  100
// miss    30   65  100    ? % when target 100
// G_LVL   20   30   40   50
// G_EXP   10   30   50  100
// found by monster rate = monster(int*2+kar) - killer(int) / 80
// found by player rate  = victim(int+kar) - killer(int) / 80
// remark L3 will damage himself hp 20.
#include <mudlib.h>
#include "/d/magic/magic.c"
#define TYPE "black-magic"

inherit DAEMON;

#define self_damage 20
#define find_rate 80

int query_gain_spell_exp(int level)
{
	switch( level ) {
		case 0 : return  10;
		case 1 : return  30;
		case 2 : return  50;
		case 3 : return 100;
		default : return  0;
	}
}

int query_need_spell_level(int level)
{
	return 20+10*level;
}

int query_need_skill(int level)
{
	switch( level ) {
    case 1 : return  90;
    case 2 : return  95;
    case 3 : return 100;
   default : return  80;
  }
}

int query_sp_cost(object caster, int level, string target) 
{
  int sp;
  switch( level ) {
    case 1 : sp =  80; break;
    case 2 : sp = 120; break;
    case 3 : sp = 200; break;
   default : sp =  40; break;
  }
  return modify_sp_cost(caster, sp, TYPE, query_need_spell_level(level));
}

int query_damage(object caster,int level)
{
  int dam;
  
  switch( level ) {
    case 1 : dam =  90; break;
    case 2 : dam = 140; break;
    case 3 : dam = 180; break;
   default : dam =  40; break;
  }
  return modify_damage(caster, dam, TYPE, query_need_spell_level(level));
}

int query_delay_time(int level)
{
  switch( level ) {
    case 1 : return 2;
    case 2 : return 3;
    case 3 : return 4;
   default : return 2;
  }
}

string query_effect_func(int level)
{
  if( level < 3 )
    return "effect_one";
  else
    return "effect_all";
}

int query_find_rate(object caster, object victim)
{
  if( !userp(victim) )
    return (int)victim->query_stat("int")*2 -
           (int)caster->query_stat("int") -
           modify_find_rate(caster)+
           (int)victim->query_stat("kar");
  else
    return (int)victim->query_stat("int") -
           (int)caster->query_stat("int") +
           (int)victim->query_stat("kar");
}

int cast(int level, string target)
{
	int chinese_mode, delay_time;
	object targ, me;

	me = this_player();
	chinese_mode = can_read_chinese();
	
	if( (int)me->query_skill("black-magic") < query_need_skill(level) ) {
	  tell_object( me, 
        "你的黑魔法技能不足以使用這等級的魔法! \n" );

      return 0;
    }
    
	if( target=="NONE" && !(targ = me->query_attacker()) ) {
		write( "要對誰施展爆炎核融術？\n");
	    return 0;
	} else {
		if( !targ ) 
			targ = present( target, environment(me) );
		if( !targ ) { 
		  write("你的目標並不在這裡！\n");
	      return 0;
	    }
	}

	if( !living(targ) ) { 
	  write( "爆炎核融術的目標必須是生物！\n");
      return 0;
    }
	if( targ->query("no_attack") ) { 
	  write("不—可—以。\n");
	  return 0;
	}
	if( targ==me ) {
	   write("這 .... 不太好吧。\n");
       return 0;
    }
    if( !check_level( me, targ, 1 ) ) return 0; 
	me->block_attack(query_delay_time(level)*2);
	me->set_temp("cast_busy",1);
	me->set_temp("msg_stop_attack", 
 	        "( 你正在施法，無法攻擊。 )\n"   );
	write(set_color(sprintf("你開始念起爆炎核融術咒文 依得巴拉米 美加芙雷亞 .... \n" ),"HIM",));
	tell_room( environment(me), 
	    sprintf("%s開始喃喃自語。\n" ,me->query("c_name")),
	  me);
	if( !targ->query_attackers() && 
	    (random(find_rate)<query_find_rate(me, targ)) ) {
		tell_object( me, set_color(
			sprintf("\n%s(%s)發現你對他不懷好意而開始攻擊你。\n",
				targ->query("c_name"), targ->query("name")) ,"HIY",me));

		tell_room( environment(targ), 
			sprintf("%s發現%s對他不懷好意而主動攻擊。\n",
				targ->query("c_name"), me->query("c_name")) , me);
	  targ->kill_ob(me);
	  me->block_attack(2);
	}
	if( me->query("npc") && me->query("magic_delay") )
		delay_time = (int)me->query("magic_delay")*2;
	else
		delay_time = query_delay_time(level)*2;
	call_out( "pre_effect", 1, me, targ, level);
	if (delay_time > 2) call_out("pre_effect1", 2 , me, targ);
	if (delay_time > 4) call_out("pre_effect1", 4 , me, targ);
	call_out( query_effect_func(level), delay_time, level, me, targ );
	return 1;
}

void pre_effect( object caster, object target, int level )
{
    if( level < 1 ) { 
      tell_object( caster,set_color(sprintf( 
	"一團炙熱的爆炎球開始在你的手中聚集、成長著。\n"),"HIM",));

	  tell_room( environment(caster), sprintf(
		"一團小小的黑暗球體在%s  的手中迅速地形成。\n" ,caster->query("c_name") ),
		caster);
	} else if( level < 2 ) {
	  tell_object( caster,set_color(sprintf(
		"你的手中開始聚集一團巨大炙熱的爆炎球。\n"),"HIM",));

	  tell_room( environment(caster), 
		 
sprintf("%s的手中開始聚集一團黑暗的魔法球體, 隨著四周的光芒不斷地向球體中心聚集, 球體開始膨脹、巨大化。\n" ,caster->query("c_name"))
		,caster);
	} else if( level < 3 ) {
	  tell_room( environment(caster),set_color(sprintf(
        "突然天昏地暗, 大地變色, 似乎有甚麼可怕的事情將要發生。\n" 
	  ),"HIM"));
	} else {
	  tell_room( environment(caster),set_color(sprintf( 
        "突然天昏地暗, 大地變色, 動物們驚慌的流竄奔跑, 似乎有甚麼\n可怕的事情將要發生。\n" 
	  ),"HIM",));
	  tell_room( environment(caster), 
        "你的本能告訴你, 最好趕快離開。\n" , caster
	  );
	}
	if( !target || !present(target, environment(caster)) ) 
		caster->set_temp("cast_flee",1);
}

void pre_effect1(object caster, object target)
{
	if( !caster ) return;
	if( !target || !present(target, environment(caster)) ) 
		caster->set_temp("cast_flee",1);
}

void effect_one(int level, object caster, object victim)
{
	int damage;
    
    if ( !caster ) return;
    caster->set_temp("cast_busy",0);
    damage = query_damage(caster, level);
	damage += random((int)caster->query_stat("int"));
	
	if( !victim || !present(victim, environment(caster)) )
	  if( level < 2 ) {
		tell_object( caster, 
		  "你將手中的爆炎球往地上一砸, 「轟」的一聲爆炸了。\n");

		tell_room( environment(caster), 
		 sprintf("%s將手中的爆炎球往地上一砸, 「轟」的一聲就爆掉了。\n",
		  caster->query("c_name") ), caster  );
		gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
		return;
	  } else {
	    tell_room( environment(caster), 
		  "但是什麼事情都沒有發生。\n" 
		);
		gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
		return;
      }
    if( level < 2 &&
    	!success_hit( 30+level*35, caster, TYPE, query_need_spell_level(level) ) ) {
      tell_object( caster, 
        "你將手中的爆炎球丟出去，可惜沒有擊中敵人。\n");
      tell_room( environment(caster), 
        sprintf("%s將手中的爆炎球丟出去，但是沒打中任何人。\n",
		  caster->query("c_name") ), caster);
	  gain_spell_experience(caster, TYPE, query_gain_spell_exp(level)/2);
      return;
    }
// hit effect ...
    if( level < 1 ) {
	  tell_object( caster, 		sprintf(bold("你將手中的爆炎球丟出去，「轟」的一聲在%s的面前炸開！\n",caster),
			victim->query("c_name")) );

	  tell_object( victim,
	sprintf("%s將手中那團黑暗、炙熱的球體往你的臉上丟過來，「轟」的一聲在你面前炸開！\n",
			caster->query("c_name") ));

	  tell_room( environment(caster), 
		sprintf("%s將手中的黑暗球體丟出去，「轟」的一聲在%s的面前炸開！\n",
			caster->query("c_name"), victim->query("c_name") )
		,({ caster, victim })
	  );
	} else if( level < 2 ) {
	  tell_object( caster,
		sprintf(bold("你將手中的大爆炎球丟出去，「轟隆」的一聲在%s身上炸開！\n",caster),
			victim->query("c_name")) );

	  tell_object( victim, 
		sprintf("%s將手中的黑暗球體「轟隆」的一聲, 在你面前炸開！高熱的火□重重地燒灼著你的皮膚。\n",
			caster->query("c_name") ));

	  tell_room( environment(caster), 
		sprintf("%s將手中的黑暗球體「轟隆」的一聲在%s身上炸開, 同時化成一團黑暗的火□焚燒著%s！\n",
			caster->query("c_name"), victim->query("c_name"), victim->query("c_name") )
		    , ({ caster, victim })
	  );
	} else if( level < 3 ) {
	  tell_object( victim, 
		sprintf(bold("%s手中的黑暗球體突然擴大, 籠罩在你的四周。接著一隻黑色的火龍\n突然從天 而降，往你身上噴出灼熱火□！\n",caster)
		  ,caster->query("c_name") ));

	  tell_room( environment(victim), 
		sprintf("%s手中的黑暗球體化成一個魔法陣圍繞著%s, 接著一隻黑色的火龍\n突然從天而降，往%s身上噴出灼熱火□！\n"
		  ,caster->query("c_name"), victim->query("c_name"), victim->query("c_name") )
		, ({ caster, victim }));

	  tell_object( caster, 
		sprintf(bold("你手中的黑暗球體化成一個魔法陣圍繞著%s, 接著一隻黑色的火龍\n突然從天而降，往%s身上噴出灼熱火□！\n",caster)
		  ,victim->query("c_name"), victim->query("c_name") ));
	}
	
	damage -= random((int)victim->query_stat("int"));
	damage -= (int)victim->query("defense_bonus")/4 +
	          random((int)victim->query("defense_bonus")/2);
	if( damage < 0 ) damage = 1;
	victim->kill_ob(caster);
	caster->kill_ob(victim);
	gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
	caster->gain_experience(damage);
	victim->receive_special_damage( "none", damage, 1 );
	victim->set("last_attacker", caster);
    report( caster, victim );
}

int is_a_victim( object obj )
{
    if( living(obj) ) return 1;
}

void effect_all( int level, object caster, object targ )
{
    object *victim;
    int i,damage;
    
    if (!caster) return;
    caster->set_temp("cast_busy",0);
    gain_spell_experience(caster, TYPE, query_gain_spell_exp(level));
    damage = query_damage(caster, level);
    damage += random((int)caster->query_stat("int"));
    
    tell_object( caster,
      sprintf( bold(
      "龍王「巴哈姆特」突然從天而降，往你身上噴出炙熱火□。\n 不過你周圍一股無形的力場擋住了火□，減低了傷害！\n",caster )));

    tell_room( environment(caster), 
	  "龍王「巴哈姆特」突然從天而降，往你身上噴出炙熱火□。你覺得你\n 
的身體逐漸失去知覺，所有的細胞開始分解 ，像蒸發了一樣——氣化了！\n"
	  ,caster
	);
	
	caster->receive_damage( self_damage );
    victim = filter_array( all_inventory( environment( caster ) ),
             "is_a_victim", this_object() );
    if( sizeof(victim) ) {
      i = sizeof(victim);
      while(i--)
       if( (victim[i] != caster) && !(victim[i]->query("no_attack")) &&
           check_level( caster, victim[i], 0 ) ) {
        damage -= random((int)victim[i]->query_stat("int"));
        damage -= (int)victim[i]->query("defense_bonus")/4 +
                  random((int)victim[i]->query("defense_bonus")/2);
        if( damage < 0 ) damage = 1;
        victim[i]->kill_ob(caster);
	    caster->kill_ob(victim[i]);
	    caster->gain_experience(damage);
	    victim[i]->receive_special_damage( "none", damage, 1 );
	    victim[i]->set("last_attacker", caster);
	    report( caster, victim[i] );
       }
    }
}
