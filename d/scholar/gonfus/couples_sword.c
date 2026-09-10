#include <mudlib.h>

#define GONFU_DIR    "scholar/"
#define GONFU_NAME   "couples_sword"

inherit DAEMON;

int check_weapon(object me)
{
  object weapon;

  if (!me)
    return 0;

  if (!me->query_temp("gonfu_busy"))
    return 0;

  weapon=(object)me->query("weapon1");
  if( !weapon || (string)weapon->query("type") != ("longblade") ) {
           tell_object(me,"你並未裝備適合的武器。\n");
           tell_object(me,
                "你吸了一口氣, 停止使用"+to_chinese(GONFU_NAME)+"。\n");

        tell_room( environment(me),
                me->query("c_name")+
                "輕輕的吐出一口氣，收式而立。\n" , me);

        me->delete("attack_skill");
        me->delete("defense_skill");
        me->delete_temp("gonfu_busy");
        me->delete_temp("extra_db/couples_sword");
        return 0;
  }
  call_out("check_weapon",2,me);
  return 1;
}

int check_spouse(object me)
{

  /* obj_id 是為了考量性別可能不會剛好是一男一女而設的 */
  int obj_id1, obj_id2, i;
  string spouse_name, trash, temp;
  object spouse, env;

  spouse_name = me->query("spouse");
  if (!spouse_name) {
    tell_object(me,"你想還是先結婚再說吧。\n");
    return 0;
  }
                                            
  me = this_player();
  env = environment(me);
  spouse_name = lower_case(spouse_name);
  spouse = find_living(spouse_name);
  if ( !spouse || !present(spouse,env) ) {
    tell_object(me,"因為缺少你另一半的輔助而無法施展這套劍法。\n");
    return 0;
  }
 
  temp = identify(spouse);
  sscanf(temp,"%s#%d",trash,obj_id1);
  temp = identify(me);
  sscanf(temp,"%s#%d",trash,obj_id2);
  if (obj_id1>obj_id2) 
    if (spouse->query("gender") == "male") i = 2;
    else i = 1;
  else 
    if (me->query("gender") == "male") i = 1;
    else i = 2;     
  me->set_temp("enhant_seq", i );
  spouse_name = spouse->query("c_name");
  me->set_temp("c_spouse",spouse_name);
  return 1;
}


int enhant(object me, int level)
{
	object weapon;
	
	weapon = (object)me->query("weapon1");

        if( !weapon || (string)weapon->query("type") != ("longblade") ) {
           tell_object(me,"你並未裝備適合的武器。\n");
           return 0;
        }
        
        if (!check_spouse(me))
          return 0;                                  
        
	tell_object(me, 
		"\n你開始將內力聚於劍身, 準備使出「"+
		to_chinese(GONFU_NAME)+"」!!\n");

	tell_room( environment(me),
		"\n"+me->query("c_name")+
		"大喝一聲，將手上的"+weapon->query("short")+
		"一抖，準備施展那難得一見的"+
                to_chinese(GONFU_NAME)+"。\n" , me);

	me->set("attack_skill", GONFU_DIR+GONFU_NAME); 
	me->delete("defense_skill");
	me->set_temp("gonfu_busy",1);
	call_out("release_gonfu", 20+level, me);
        call_out("check_weapon",2,me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
        if (!me->query_temp("gonfu_busy"))
          return;
	tell_object(me, 
		"你吸了一口氣, 停止使用"+to_chinese(GONFU_NAME)+"。\n");
 
 	tell_room( environment(me),
 		me->query("c_name")+
 		"輕輕的吐出一口氣，收式而立。\n" , me);
 
	me->delete("attack_skill");
	me->delete("defense_skill");
	me->delete_temp("extra_db/couples_sword");
	me->delete_temp("gonfu_busy");
}
