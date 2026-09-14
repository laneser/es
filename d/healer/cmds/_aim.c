////#pragma save_binary
#include <mudlib.h>
#define VALID_LOC ({ "vascular", "ganglion", "weakest", "critical" })

inherit DAEMON;

int help();

int cmd_aim(string str)
{
	string loc;

	if( !str || str=="" ) {
		if( (loc= this_player()->query( "aiming_loc" )) ) {
			write( "你現在設定戰鬥時瞄準: " + loc + " ( " + to_chinese(loc) + " )\n" );
			return 1;
		}
		return help();
	}
	if( !this_player()->query_skill("anatomlogy") )
		return notify_fail( "你並沒有學過解剖學 ....。\n" );
	if( member_array(str, VALID_LOC)==-1 ) return help();
	this_player()->set("aiming_loc", str);
	write( "Ok.\n" );
	return 1;
}

int help()
{
	write(@C_HELP
指令格式: aim <部位>

這個指令讓你在戰鬥中嘗試去打中敵人的某些特殊部位，這些部位一旦打中，有可
能造成敵人各種損傷或是能力的降低，命中率視敵人的不同、瞄準的部位和你的解
剖學技能與所使用的武器而定。

你所能瞄準的部位有:

ganglion -     神經聚集的地方，擊中後可以令敵人在幾回合內無法攻擊。
vascular -     血管聚集的地方，擊中後可以使敵人血流不止。
weakest -      敵人防禦力最弱的部位，擊中後可以使敵人受到你目前所能造成
               的最大傷害。
critical -     敵人的致命弱點，擊中後使敵人的體力立即降到 1/3 以下，不過
               成功機會不大。

C_HELP
	);
	return 1;
}
