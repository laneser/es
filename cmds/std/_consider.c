//#pragma save_binary

// Estimate command
// By Annihilator@Eastern.Stories

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int cmd_consider(string arg)
{
	int my_power, dest_power, diff;
	int alignment, ethics_skill;
	object dest, me;

	if( this_player()->query("stop_attack") > 0 )
		return notify_fail( 
			"( 你還沒有完成上一個動作，無法評估任何怪物。 )\n");

	if( !arg || arg=="" )
		return notify_fail( 
			"指令格式: consider <怪物名>\n");

	if( !dest= present( arg, environment(this_player()) ) )
		return notify_fail(
			"這裡沒有這種怪物。\n");

	me = this_player();
	me->calc_weapon_class();
	my_power = ((int)me->query("weapon_class1") - (int)dest->query_stat("dex"))*3 + 50;
	if( my_power < 5 ) my_power = 5;
	if( my_power > 95 ) my_power = 95;
	my_power *= (((int)me->query("min_damage1") + (int)me->query("max_damage1"))/2
		- (int)dest->query("defense_bonus"));
		
	dest->calc_weapon_class();
	dest_power = ((int)dest->query("weapon_class1") - (int)me->query_stat("dex"))*3 + 50;
	if( dest_power < 5 ) dest_power = 5;
	if( dest_power > 95 ) dest_power = 95;
	dest_power *= (((int)dest->query("min_damage1") + (int)dest->query("max_damage1"))/2
		- (int)me->query("defense_bonus"));
	
	// Make bias with skill	
	my_power += 1000 * random(100-(int)me->query_skill("consider")) / 100;
	dest_power -= 1000 * random(100-(int)me->query_skill("consider")) / 100;

	diff = my_power - dest_power;
	if( diff < -3000 ) write( 
	    "我想一定是某位巫師在戲弄你，就算十個19級的player也撐不住他一下攻擊。\n");
	else if( diff < -2000 ) write( 
		"別傻了，你大概有一半以上的機會在一回合內被殺。\n");
	else if( diff < -1000 ) write( 
		"如果你穿著全套最好的盔甲，手持稀世寶刀，外帶一大堆恢復藥劑，也許....\n");
	else if( diff < -500 ) write( 
		"你贏的機會很低，對方的各項能力都比你強很多。\n");
	else if( diff < -200 ) write( 
		"這種對手以你目前的能力而言，似乎有點勉強。\n");
	else if( diff < -50 ) write( 
		"如果你的運氣不錯，要打贏這樣的敵人並不是很難。\n");
	else if( diff < 50 ) write(
		"對方和你是半斤八兩，旗鼓相當。\n");
	else if( diff < 200 ) write( 
		"只要你不出什麼紕漏，這樣的敵人很好對付。\n");
	else if( diff < 500 ) write( 
		"對方的各種能力都比不上你，不必擔心。\n");
	else if( diff < 1000 ) write(
		"這種敵人對你而言，完全不構成任何威脅。\n");
	else if( diff < 2000 ) write(
		"我相信你可以在三回合內把這傢伙幹掉。\n");
	else write( 
		"老實說，欺負這種弱小敵人實在是浪費時間。\n");

	if( ethics_skill =me->query_skill("ethics") ) {
		alignment = (int)dest->query("alignment") 
			- random((100-ethics_skill)*20) + (100-ethics_skill) * 10;
		write(
			"你認為這是個「" + STATS_D->alignment_string(alignment) + "」之流的對手。\n");
	}
	return 1;
}

int help()
{
	write( @HELP
使用格式: consider <生物名字>

這個指令將判斷生物的強弱，準確程度受技能影響.
如果你的評估技能等級高，會大大提高評估準確度.
HELP
	);
	return 1;
}
