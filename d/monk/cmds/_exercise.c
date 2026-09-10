//#pragma save_binary

#include <mudlib.h>
#include <daemons.h>
#include <conditions.h>

inherit DAEMON;

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
        some_stat = some_stat - 2;

	call_other( EXERCISING, "remove_effect", player, 1 );
	tell_object( player, set_color( ( 
		"\n你感到胸口一陣氣血翻湧，眼前金星亂冒，看來是走火入魔的徵兆 ....\n"+
		( some_stat > 1 ? "\n你的" + to_chinese(stat) + "降低了！\n":"")+
		"\n你深深吸進一口氣，勉強壓制住體內四處亂竄的真氣，站了起來 ....\n\n")));
	tell_room( environment(player), 
		player->query("c_name") + "受到了驚擾，整個人一陣顫抖，臉上痛苦地扭曲著 ....\n\n"
		+ player->query("c_name") + "深深地吸了一口氣，搖搖晃晃地站了起來 ....\n\n" ,
		player );

	if( some_stat < 1 ) player->receive_damage(player->query("max_hp"), 0);
	else STATS_D->change_perm_stat(player, stat, some_stat);

	// skip all NPCs, for stop system hole, added by Kyoko.
	if( victim && living(victim) && !victim->query("npc") && !flag ) {
		fp = (int)player->query("force_points") - (int)victim->query("force_points");
		if( fp > 0 ) {
			if( !victim->query("force_points") ) fp += 200;
//			if( (string)victim->query("class")="monk" ) fp += 800;
			victim->set("last_attacker", player);
			victim->receive_damage(fp/ (1+random(2)) );
			tell_object( victim, 
				"\n你感到" + player->query("c_name") + "身上傳來一股巨力，震得你胸口一陣氣血翻湧！\n\n");
		}
	}
}

int cmd_exercise( string arg )
{
	int exe_skill, max,fe;
	object me;
	
	me = this_player();
	exe_skill = (int)me->query_skill("inner-force");
	if( !exe_skill ) return notify_fail("你沒有學過修習內功的方法 ....。\n");

    if( me->query("conditions/exercising") )
        return notify_fail("你剛運功不久，體內充滿真氣，不適合操之過急馬上再練。\n");

    if( me->query_attackers() )
         return notify_fail("你不能在戰鬥運功，小心走火入魔 !!\n");
    if(me->query("monk_songin") )
         return notify_fail("你正在集中精神誦經，無法運功!!\n");

	if( me->query("stop_heal") )
         return notify_fail("你現在不能運功。\n");

	if( !arg || !sscanf(arg, "%d", max) ) max = exe_skill / 3;
        fe=(int)me->query("force_effect");
    max = max/2 + random(max/2) + random(fe);
	if( max < 1 ) max = 1;
	if( max > 35 ) max = 35;
	write("你寬袍緩帶，盤腿而坐，眼觀鼻，鼻觀心，一股內息開始在你的體內流動 ...。\n");
	tell_room( environment(me), 
		me->query("c_name")+ "盤腿坐了下來，閉目凝神，開始打坐。\n", me );
	me->set_temp("exercising", base_name(this_object()));
        EXERCISING->apply_effect(me, max, 60+max+random(max)+fe*3);
	return 1;
}

int help()
{
    write(@HELP
Syntax: exercise <cycle>

This command lets you relax your body strength, concentrating on regeneration
of inner force. Because inner force is hard the regenerate, it is dangerous
to exercise in public. If you are disturbed while exercising your inner force,
one of your physical attribute is REDUCED TO HALF of original level permently.
And there is also a chance to cause some extra bad condition if you are 
exercising some special inner force.
You can specify the ammount of cycle you wish to exercise, but how long you
can exercise depend on your basic inner-force skill.
HELP
	);
    return 1;
}
