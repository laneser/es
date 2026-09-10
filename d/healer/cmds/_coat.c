//	_coat.c		淬毒術
//
//		Lilia@Eastern.Stories

// 所需技能：毒物學 50
// 傷害力為毒藥本身傷害力 * skill%
// 命中率為毒藥本身困難度 + 陣營值/10000
	////#pragma save_binary
#include <mudlib.h>

inherit DAEMON;

int cmd_coat(string arg)
{
    object p, weapon, poison;
    int ali, i, skill;
    string wname, pname;

    p = this_player();

    if (!arg || arg == "")
	return notify_fail("你想做什麼?\n");

    sscanf (arg, "%s with %s", wname, pname);
    if (!wname || wname == "" || !pname || pname == "")
	return notify_fail("你想做什麼?\n");

    if (weapon = present(wname, p))
	if (weapon->query("weapon_class"))
	    ;
	else
	    return notify_fail("這不是武器。\n");

    if (poison = present(pname, p))
        if (poison->query("poison_type"))
            ;
        else
            return notify_fail("這不是毒藥。\n");

    if (weapon && poison)
    { 
    	skill = p->query_skill("venomlogy");
    	if (skill < 50)
	    return notify_fail("遠處傳來女王的笑聲: 年青人，別傻了，練個十年再來吧!\n");

	ali = this_player()->query("alignment");
        if (ali >= 0)
            return notify_fail("你心中一陣天人交戰，下不了這個手 ...\n");

    	if (p->query("stop_attack") != 0)
	    return notify_fail("你上個動作還沒有完成，不能替武器淬毒。\n");

    	if (weapon->query("poisoned/type"))
	    return notify_fail("這個武器已經上過毒了，沒有辦法重複淬毒。\n");

        write("你替"+weapon->query("c_name")+"塗上"+poison->query("c_name")+"。\n");

    	weapon->set("poisoned/type", poison->query("poison_type"));
    	weapon->set("poisoned/time", poison->query("poison_time"));
    	weapon->set("poisoned/duration", poison->query("poison_duration"));
    	weapon->set("poisoned/harm", poison->query("poison_harm") * skill / 100);
    	i = 100 - poison->query("poison_diff") - ali/10000;
    	i = (i > 100) ? 100 : i;
    	weapon->set("poisoned/hit_rate", i);
        poison->remove();
    	return 1;
    }
    else
	return notify_fail("你沒有這樣東西。\n");
}

int help()
{
    write(
    @C_HELP
指令格式： coat <武器> with <毒藥>

這個指令可以讓你替某樣武器塗上毒藥，使武器的威力增強。這個指令
必須是受過良好毒物學訓練的邪惡醫師方可使用。
C_HELP
    );
    return 1;
}

