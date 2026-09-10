//#pragma save_binary

#include <mudlib.h>
#include <daemons.h>
#include <conditions.h>

inherit DAEMON;

int help();

void create()
{
	seteuid(getuid());
}

varargs void disturbed(object player, object victim, int flag)
{
	string stat;
	int some_stat, n, fp;

	if (!player->query_attacker()) return;
	switch( n = random(3) ) {
		case 0: stat = "strength";		break;
		case 1: stat = "dexterity";		break;
		case 2: stat = "constitution";	break;
	}

	some_stat = (int)player->query_perm_stat(stat);
    some_stat = some_stat * 2 / 3;

	call_other(EXERCISING, "remove_effect", player, 0);
	tell_object( player, set_color( 
		"\n你感到胸口一陣氣血翻湧，眼前金星亂冒，看來是走火入魔的徵兆 ....\n"+
		( some_stat > 1 ? "\n你的" + to_chinese(stat) + "降低了！\n":"")+
		"\n你深深吸進一口氣，勉強壓制住體內四處亂竄的真氣，站了起來 ....\n\n", "HIY", player) );
	tell_room( environment(player), 
		player->query("c_name") + "受到了驚擾，整個人一陣顫抖，臉上痛苦地扭曲著 ....\n\n"
		+ player->query("c_name") + "深深地吸了一口氣，搖搖晃晃地站了起來 ....\n\n" ,
		player );

	// skip all NPCs, for stop system hole, added by Kyoko.
	if( victim && living(victim) && !victim->query("npc") && !flag ) {
		fp = (int)player->query("force_points") - (int)victim->query("force_points");
		if( fp > 0 ) {
			if( !victim->query("force_points") ) fp += 200;
			victim->set("last_attacker", player);
			victim->receive_damage(fp/3);
			tell_object( victim, 
				"\n你感到" + player->query("c_name") + "身上傳來一股巨力，震得你胸口一陣氣血翻湧！\n\n");
		}
	}

	if( some_stat < 1 ) player->receive_damage((int)player->query("max_hp"), 0);
	else {
		STATS_D->change_perm_stat(player, stat, some_stat);
		CONFUSED->apply_effect(player, (int)player->query("force_points")/5, 3);
	}
}

int cmd_chutan(string arg)
{
	int skill, max;
	object me;

	if( arg ) return help();
	me = this_player();
	skill = (int)me->query_skill("chutan");
	if( !skill ) return notify_fail("你沒有學過修習過聚丹功的心法 ....。\n");

    if( me->query("conditions/exercising") )
        return notify_fail("你剛運功不久，體內充滿真氣，不適合操之過急馬上再練。\n");

    if( me->query_attackers() )
         return notify_fail("你不能在戰鬥聚丹，小心走火入魔 !!\n");

   if( me->query_temp("meditating")) return notify_fail("你正在打坐，無法聚丹...。\n");
	if( me->query("stop_heal") )
         return notify_fail("你現在不能運功\。\n");

	max = skill / 3;
    max = max/2 + random(max/2) + (int)me->query("force_effect");
	if( max < 1 ) max = 1;
	if( max > 35 ) max = 35;
	write("你寬袍緩帶，盤腿而坐，眼觀鼻，鼻觀心，一股內息開始在你的體內流動 ...。\n");
	tell_room( environment(me), 
		me->query("c_name")+ "盤腿坐了下來，閉目凝神，開始聚氣。\n", me );
	me->set_temp("exercising", base_name(this_object()));
	EXERCISING->apply_effect(me, max, 5*max-random(skill/5));
	return 1;
}

int help()
{
    write(@HELP
指令格式： chutan

這個命令讓你放鬆你的身體，集中精神產生內力，因為內力很難在生故在公眾場所
聚丹是相當危險的。假如你在聚丹時被打擾則你的基本屬性將會從原來的值下降，
也可能產生其他一些不良的影響。
HELP
	);
    return 1;
}
