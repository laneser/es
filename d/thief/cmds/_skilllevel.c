#include <mudlib.h>
inherit DAEMON;
int cmd_skilllevel()
{
	object owner;
	owner = this_player();
tell_object(owner,
"姓名 : "+owner->query("c_name")+"\n"
"\t技能\t\t等級\t\t經驗\n"
"\t背刺\t\t"+owner->query("thief_level/backstab")+"\t\t"+owner->query("thief_exp/backstab")+"\n"
"\t射飛刀\t\t"+owner->query("thief_level/throw-dagger")+"\t\t"+owner->query("thief_exp/throw-dagger")+"\n" );
// "\t偷竊\t\t"+owner->query("thief_level/steal")+"\t\t"+owner->query("thief_exp/steal")+"\n" );
	return 1;
}

int help()
{
	write(@HELP
指令格式 : skilllevel
    這個指令讓你知道目前你各種技能的等級。
HELP
	);
}

