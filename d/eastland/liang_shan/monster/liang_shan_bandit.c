// liang_shan_bandit.c 
#include <mudlib.h>
#define HEADQUARTER "/d/eastland/liang_shan/daemons/army_d"

inherit MONSTER;

void create()
{
	::create();
	HEADQUARTER->add_member();
}

void remove()
{
	HEADQUARTER->remove_member();
	return ::remove();
}

int stop_attack()
{
	HEADQUARTER->add_huntee(this_player());
	return 0;
}

void pseudo_hunt(object me, object player)
{
	if( environment() && present(player, environment()) ) 
		if( this_object()==me )
			tell_room( environment(), 
				query("c_name") + "發現你的意圖，大叫: 兄弟們！看清楚這傢伙，別讓他跑了！\n",
				this_object() );
		else {
			tell_room( environment(), 
				query("c_name") + "衝到你面前，大喝:「不要命的傢伙，敢來梁山撒野，去死吧！」\n",
				this_object() );
			if( !pointerp(attackers) || member_array(player, attackers)==-1 )
				kill_ob(player);
		}
	else if( !pointerp(will_attack) )
		will_attack = ({ player });
	else if( member_array(player, will_attack)==-1 )
		will_attack += ({ player });
}
