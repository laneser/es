// 氣盾術
//
//		Lilia

////#pragma save_binary

#include <mudlib.h>

#define QUESTNAME "lost_kingdom"
#define SP_COST	50

int help();

int remove_block(object obj)
{
    obj->delete_temp("block_command");
    return 1;
}

int cmd_amass()
{
    int skill, delay_time;
    object me;

    me = this_player();
    if ((int)me->query(QUESTNAME) != 8) return 0;

    skill = me->query("dou-in");
    if (!skill)
	return notify_fail("你還沒練過氣功，沒有辦法聚氣。\n");

    if ((int)me->query("stop_attack") > 0)
	return notify_fail("( 你上一個動作還沒有完成，無法專心聚氣。 )\n");

    if (!(!(me->query_current_attacker())))
	return notify_fail("你還在戰鬥中，沒時間停下來聚氣。\n");

    if (me->query_temp("no_concentrate"))
	return notify_fail("你的注意力還不能集中，無法聚氣。\n");

    if (me->query("spell_points") < SP_COST)
	return notify_fail("你的真氣不足，無法聚氣。\n");

    if (me->query("npc"))
	delay_time = 0;
    else
	delay_time = 3;

    me->block_attack(delay_time);
    me->set_temp("msg_stop_attack", "( 你正在專心聚氣，沒辦法做其他事! )\n");
    tell_object(me, "你閉目凝神，開始聚氣 ...\n");
    tell_room(environment(me), me->query("c_name")+"閉目凝神，開始聚氣 ...\n", me);
    call_out("effect", delay_time, me);
    return 1;
}

void effect(object me)
{
    int duration, sp;

    if (me->query_temp("effect/protect"))
	tell_object(me, "一陣微風輕輕地拂在你的臉上，令你覺得十分清爽 ...\n");
    else
	tell_object(me, "一陣旋風呼應著你體內真氣的流動，圍繞在你的四周形成了氣盾保護著你!\n");

    tell_room(environment(me), "似乎有一陣風圍繞在"+me->query("c_name")+"的四周 ... 該不會是錯覺吧? ...\n", me);

    duration = me->query_stat("pie") * 3 + 50;
    me->set_temp("extra_db/protect", (int)me->query("dou-in"));
    me->set_temp("extra_ac/protect", 10);
    me->set_temp("effect/protect", 1);
    me->calc_armor_class();
    me->delete_temp("msg_stop_attack");
    sp = (int)me->query("spell_points");
    sp -= SP_COST;
    me->set("spell_points", sp);
    call_out("expire", duration, me);
}

void expire(object me)
{
    if (!me) return;

    tell_object(me, "你覺得四周的風勢小了下來，氣盾消失了 ...\n");

    me->delete_temp("extra_db/protect");
    me->delete_temp("extra_ac/protect");
    me->delete_temp("effect/protect");
    me->calc_armor_class();
}

