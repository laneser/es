//	_deplete.c	放血解毒術
//
//		Lilia
	////#pragma save_binary
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit DAEMON;

int cmd_deplete(string arg)
{
    object dest, weapon;
    int skill, skill2;
    mixed poisoned;

    if (!arg || arg == "" || !(dest = present(arg, environment(this_player()))))
  	return notify_fail("你想替誰解毒? \n");
    
    if (!living(dest)) return notify_fail("這個「東西」會中毒嗎? \n");

    if (dest->query("npc")) return notify_fail("你不能替 NPC 放血。\n");

    if (dest->query("ghost")) return notify_fail("要上大體解剖到醫學院去，不要拿死屍開玩笑！\n");
    
    weapon = this_player()->query("weapon1");
    if ((!weapon) || (string)weapon->query("type") != "dagger")
	return notify_fail("你沒有裝備適當的工具，沒辦法放血。\n");

    if (this_player()->query("stop_attack") != 0)
        return notify_fail("你的上個動作還沒有完成，沒辦法替人放血。\n");

    if (!(poisoned = dest->query("conditions/simple_poison")))
        return notify_fail("想 PK 直接打 kill <某人> 就可以了，不必放血。\n");

    if (dest->query_temp("depleted"))
	return notify_fail("患者剛放過血，不能立刻再行放血。\n");
    
    if ((int)dest->query("hit_points") <= 20)
	return notify_fail("患者已經奄奄一息了，恐怕經不起放血的治療。\n");

    skill = (int)this_player()->query_skill("clotting");
    if (!skill) return notify_fail("沒學過止血就想放血? 不好吧 ....\n");

    skill2 = (int)this_player()->query_skill("anatomlogy");
    if (!skill2) return notify_fail("沒學過解剖學就想放血? 回去練個十年再來吧!\n");

    write("你替" + dest->query("c_name") + "進行放血 ....\n");
    tell_object(dest, this_player()->query("c_name") + "替你進行放血 ... 你覺得好多了!\n");
    tell_room(environment(this_player()), this_player()->query("c_name") + "替" + dest->query("c_name") + "進行放血。\n", ({this_player(), dest}));
   
    if (dest != this_player()) this_player()->add("alignment", 25);

    if (skill2/2 + random(skill2/2) > poisoned[1] * poisoned[2])
    {
	this_player()->receive_experience(skill2);
	(CONDITION_PREFIX + "simple_poison")->remove_effect(dest);
    }
    else
    {
	poisoned[2] /= 2;
	dest->set("conditions/simple_poison", poisoned);
	this_player()->receive_experience(skill2 / 2);
    }

    dest->set_temp("depleted", 1);
    dest->receive_damage(20 - random(skill/5)); 
    call_out("remove_depleted", 120, dest);
    return 1;
}

void remove_depleted(object player)
{
    if (player) player->set_temp("depleted", 0);
}

int help()
{
    write(
    @C_HELP
指令格式： deplete <某人>

這個指令讓你替某個人物放血解毒，放血的結果可能是完全解去毒性，
或是將毒性減半。但不論是否完全成功，患者的體力都有可能會下降，
這與施術者的止血技能有關。放過血的人大約在兩分鐘內不能再度放血
解毒，以免血液流失過多。
C_HELP
    );
    return 1;
}

