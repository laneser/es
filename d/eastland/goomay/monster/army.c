
#include <../goomay.h>

#define HEADQUARTER Mob"army_d"

inherit MONSTER;

void create()
{
	::create();
	HEADQUARTER->add_member();
}

int remove()
{
	HEADQUARTER->remove_member();
	::remove();
	return 1;
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
				query("c_name") + "衝到你面前，大喝:「你活得不耐煩了，竟敢到古梅鎮撒野！」\n",
				this_object() );
			if( !pointerp(attackers) || member_array(player, attackers)==-1 )
				kill_ob(player);
		}
	else if( !pointerp(will_attack) )
		will_attack = ({ player });
	else if( member_array(player, will_attack)==-1 )
		will_attack += ({ player });
}
