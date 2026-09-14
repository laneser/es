#include <mudlib.h>

inherit DAEMON;

string *c_illusion =({

"從手太陰肺經的中府穴流過、雲門、天府、俠白、尺澤、孔最穴...\n",

"衝過你的隱臼、大都、太白、公孫、商邱、三陰交穴，通往少海穴...\n",

"流向你的極泉、青靈、少海、靈道、通裡穴。\n", 

"通過了神封、靈墟、神藏、彧中、俞府，流向手少陽三焦經的觀衝穴。\n",

});

void do_heal(object player, int skill, int degree, int ok)
{
	int fp, hp, max, heal;

	fp = (int)player->query("force_points");
	if( !ok && degree < 10 && skill > random(degree*degree*2) && fp > 10 ) {
		message("illusion", can_read_chinese(player)?
			"一股真氣"+c_illusion[random(sizeof(c_illusion))]:
			"You feel some colorful illusions around you.\n", player);
		hp = (int)player->query("hit_points");
		max = (int)player->query("max_hp");
		player->set("force_points", fp-degree);
		heal = degree+degree/2+random(degree);
		if( hp + heal > max ) {
			player->set("hit_points", max );
			call_out("do_heal", 2, player, 0, 0, 1);
		} else {
			player->set("hit_points", hp+heal);
			call_out("do_heal", 2, player, skill, degree+1, 0);
		}
	} else {
		player->delete_temp("block_command");
		player->delete_temp("block_defense");
		player->delete_temp("block_message");
		player->delete_temp("gonfu_busy");
		tell_object( player, can_read_chinese(player)?
			"...... \n你深深的吸了一口氣，結束了運功療傷，你站了起來。\n\n":
			"And then you see the scene surrounding you come solid, you awake.\n" );
		tell_room( environment(player), ({
			player->query("cap_name")+" opens eyes, looks around, and then stands up.\n",
			player->query("c_cap_name")+"神清氣爽地站了起來。\n"}), player);
		call_out("heal_again", degree*10, player);
	}
}

int enhant(object me)
{
	int skill, chinese_mode;

	chinese_mode = can_read_chinese(me);
	if( !skill = (int)me->query_skill("chutan") ) {
		tell_object( me, chinese_mode?
			"你不會運功療傷的心法。\n":
			"You don't know method!\n");
		return 0;
	}

	if( me->query_attackers() ) {
		tell_object( me, chinese_mode?
			"在戰鬥中運功療傷? 想死嗎!\n":
			"You are combating, can't do that!\n");
		return 0;
	}

	if( me->query_temp("scholar_heal") ) {
		tell_object( me, chinese_mode?
			"你最好休息一下再運功療傷。\n":
			"You would better take a rest.\n");
		return 0;
	}
	
	tell_object( me, chinese_mode?
		"你坐了下來, 將精神運至空靈之境... 你開始運功療傷。\n":
		"You sit down, try to chutan for heal....\n");

	tell_room( environment(me), ({
		me->query("cap_name")+" sits down and starts to heal cycle.\n",
		me->query("c_cap_name")+"盤腿而坐，開始運功療傷...。\n"}), me );
		
	if( !wizardp(me) ) {
		me->set_temp("block_command", 1);
		me->set_temp("block_defense", 1);
		me->set_temp("block_message", 1);
	}

	me->set_temp("scholar_heal", 1);
	me->set_temp("gonfu_busy", 1);
	call_out("do_heal", 2, me, skill, 1, 0);
	return 1;
}

void heal_again(object player)
{
	if( !player ) return;
	player->delete_temp("scholar_heal");
}
