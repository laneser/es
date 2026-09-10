#include <mudlib.h>

#define MARTIAL_NAME      "monk/general/da_mo"
#define D_MARTIAL_NAME    "monk/general/d_da_mo"
#define GONFU_NAME   "da-mo"

inherit DAEMON;

int eungon(object me, int level)
{
	object weapon;
	
	weapon = (object)me->query("weapon1");
        if( !weapon || !((string)weapon->query("type") == "blunt"
                    ||   (string)weapon->query("type") == "bo" ) ) {
                tell_object(me, 
			"你並未裝備適合的武器。\n" );
		return 0;
	}

	tell_object(me, 
		"\n『看棍!』你運功於棍，準備使出「"+
		to_chinese(GONFU_NAME)+"」!!\n" );

	tell_room( environment(me), 
		me->query("c_name")+"大喝一聲，將手上的"+weapon->query("short")+
		"高高舉起，準備使用"+to_chinese(GONFU_NAME)+"。\n", me);

	me->set("attack_skill", MARTIAL_NAME); 
	me->set("defense_skill", D_MARTIAL_NAME); 
	me->set_temp("gonfu_busy",1);
        me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if( me->query("monk_gonfu/da-mo") == 35 )
            me->set_temp("gonfu_top",1);
        else me->set_temp("gonfu_top",0);
	call_out("release_gonfu", 20+level, me);
	return 1;
}

void release_gonfu(object me)
{
	if( !me ) return;
	me->set_temp("eungon_times",me->query_temp("eungon_times")-1);
	if( me->query_temp("gonfu_top") && me->query_temp("eungon_times") > 0 ) return;
	if( !me->query_temp("gonfu_busy") ) return;
	if( me->query_temp("gonfu_top") )
	    me->set_temp("gonfu_top",0);
	tell_object(me, 
		"\n\n你吸了一口氣, 停止使用"+to_chinese(GONFU_NAME)+"。\n" );
 
 	tell_room( environment(me),
 		me->query("c_name")+
 		"輕輕的吐出一口氣，收式而立。\n", me);
 
 	me->delete("defense_skill");
	me->delete("attack_skill");
	me->delete_temp("gonfu_busy");
}
