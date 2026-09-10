#include <mudlib.h>

#define MARTIAL_NAME      "monk/general/king_kong"
#define GONFU_NAME   "king-kong"

inherit DAEMON;

int eungon(object me, int level)
{
	object weapon;
	
	weapon = (object)me->query("weapon1");
	if( !weapon || !((string)weapon->query("type") == "blunt"
	            ||   (string)weapon->query("type") == "bo" ) ) {
		tell_object(me, 
			"你並未裝備適合的武器。\n");
		return 0;
	}

	tell_object(me, 
		set_color(sprintf("\n你默唸心法，雙目圓睜，準備使出「%s」!!\n",to_chinese(GONFU_NAME)),"HIM") );

	tell_room( environment(me), 
		sprintf("%s的雙眼流露出強大的氣勢，將手上的%s揮動一圈，準備使用%s。\n",me->query("c_name"),weapon->query("short"),to_chinese(GONFU_NAME))
		, me);

	me->set("attack_skill", MARTIAL_NAME); 
	me->delete("defense_skill"); 
	me->set_temp("gonfu_busy",1);
        me->set_temp("eungon_times",me->query_temp("eungon_times")+1);
        if( me->query("monk_gonfu/king-kong") == 35 )
            me->set_temp("gonfu_top",1);
        else me->set_temp("gonfu_top",0);
	call_out("release_gonfu", 30+level, me);
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
		set_color(sprintf("\n\n你吸了一口氣, 停止使用%s。\n",to_chinese(GONFU_NAME)),"HIM") );
 
 	tell_room( environment(me),
 		sprintf("%s輕輕的吐出一口氣，收式而立。\n",me->query("c_name"))
 		, me);
 
 	me->delete("defense_skill");
	me->delete("attack_skill");
	me->delete_temp("gonfu_busy");
}
