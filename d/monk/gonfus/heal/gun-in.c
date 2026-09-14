#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({

"由你的氣海穴流出，緩緩的流向背部的陽堂穴...\n",

"由督脈流向足三里穴，卻似忽遇到了阻礙而無法向前催動...\n",

"從你手少陰心經的極泉穴慢慢流出，流入手少陽小腸經的少澤穴。\n", 

"從手太陰肺經的中府穴流過、雲門、天府、俠白、尺澤、孔最穴...\n",

"衝過你的隱臼、大都、太白、公孫、商邱、三陰交穴，通往少海穴...\n",

"流向你的極泉、青靈、少海、靈道、通裡穴。\n", 

"從你的湧泉穴，通往照海穴。\n",

"通過了神封、靈墟、神藏、彧中、俞府，流向手少陽三焦經的觀衝穴。\n", });

void do_heal(object player, int skill, int degree, int ok)
{
	int fp, hp, max, alig ,heal;

	if( !player ) return;
	fp = (int)player->query("force_points");
	if( degree <= 10 && skill > random(degree*degree*2) 
		&& fp > 10 && !ok ) {
		player->quick_message(
			"一大股真氣"+c_illusion[random(sizeof(c_illusion))]);
		alig = (int)player->query("alignment");
		hp = (int)player->query("hit_points");
		max = (int)player->query("max_hp");
		player->set("force_points", fp-degree);
		if( (random(100) < 2) && (alig > 5000) ) {
			player->set("hit_points", max );
 			tell_object( player, @LONG
******************************************************************
*                   觀音大士法身突現.....                        *
*                                                                *
*  『閣下多行善事，乃一代大俠也，特以淨瓶水恢復你的全身傷痕...』 *
*  ............................ ..... ..... ...                  * 
*                                                                *
*  你發現你的傷全好了... 不禁低頭默唸觀音大士名號...             *
******************************************************************
LONG
			);
			call_out("do_heal", 5, player, 0, 0, 1);
			return;
		}
		heal = degree + random(degree/2);
		if( heal + hp > max ) {
			player->set("hit_points", max);
			call_out("do_heal", 3, player, 0, 0, 1);
		} else {
			player->set("hit_points", hp+heal);
			call_out("do_heal", 2, player, skill, degree+1, 0);
		}
	} else {
		player->delete_temp("block_command");
		player->delete_temp("block_defense");
		tell_object( player, 
			"...... \n你深深的吸了一口氣，結束了運功療傷，你站了起來。\n\n");
		tell_room( environment(player), 
			player->query("c_name")+ "神清氣爽地站了起來。\n",
			player );
	}
}

int eungon(object me, int level)
{
	int skill;

	if( !skill = (int)me->query_skill("heal-cycle") ) {
		tell_object( me, 
			"你不會運功療傷的心法。\n");
		return 0;
	}

	if( me->query_attackers() ) {
		tell_object( me, 
			"在戰鬥中運功療傷? 想死嗎!\n");
		return 0;
	}

	tell_object( me, 
		"你坐了下來, 默頌觀音心經，將精神運至空靈之境... 你開始運功療傷。\n");

	tell_room( environment(me), 
		me->query("c_name")+"盤腿而坐，開始運功療傷...。\n", me );

	if( !wizardp(me) ) {
		me->set_temp("block_command", 1);
		me->set_temp("block_defense", 1);
	}

	call_out("do_heal", 2, me, skill, 1, 0);
	return 1;
}

