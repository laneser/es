#include <mudlib.h>

#define GONFU_DIR    "scholar/"
#define GONFU_NAME   "unknow"

inherit DAEMON;

int enhant(object me, int level)
{
	object weapon;
	
	weapon = (object)me->query("weapon1");

	tell_object(me, can_read_chinese(me)?
		"\n你開始將內力聚於劍身, 準備使出「"+
		to_chinese(GONFU_NAME)+"」!!\n":
		"You prepare to use "+GONFU_NAME+" sword!!\n");

	tell_room( environment(me), ({
		"\n"+me->query("cap_name")+" is preparing to use "+GONFU_NAME+
		" gonfu!\n", "\n"+me->query("c_cap_name")+
		"大喝一聲，將手上的"+weapon->query("short")+
		"舉起，準備使出可怕的"+to_chinese(GONFU_NAME)+"。\n" }), me);

	me->set("attack_skill", GONFU_DIR+GONFU_NAME); 
	me->delete("defense_skill");
	me->set_temp("gonfu_busy",1);
	call_out("release_gonfu", 20+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
	tell_object(me, can_read_chinese(me)?
		"你吸了一口氣, 停止使用"+to_chinese(GONFU_NAME)+"。\n":
		"You make a deep breath, stop using "+GONFU_NAME+" sword!\n");
 
 	tell_room( environment(me),({
 		me->query("cap_name")+" makes a deep breath, stops using "+
 		GONFU_NAME+" sword!\n", me->query("c_cap_name")+
 		"輕輕的吐出一口氣，收式而立。\n" }), me);
 
	me->delete("attack_skill");
	me->delete("defense_skill");
	me->delete_temp("gonfu_busy");
}
