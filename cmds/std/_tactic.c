//#pragma save_binary

#include <mudlib.h>
#define TACTIC_D(x) ("/d/martial/tactic/" + x)
#define VALID_TACTIC ({ "none", "berserk", "melee", "flank", "assault" })
#define TACTIC_NUM ([ "none": 0, "berserk": 30, "melee": 50, "assault": 50,\
	"flank": 10, ])
    
inherit DAEMON;

int help();

int cmd_tactic(string str)
{
	string loc;
	
	if( !str || str=="" ) {
		if( (loc= this_player()->query( "tactic" )) ) {
			write( 
				"你現在所使用的戰術是 : " + loc + " (" + to_chinese(loc+"_tactic") + ")\n");
			return 1;
		}
		return help();
	}

	if( member_array(str, VALID_TACTIC)==-1 ) return help();

	if( (int) TACTIC_NUM[str] > (int)this_player()->query_skill("tactic") ) {
	  write(
	        "你的必須要有"+(string)TACTIC_NUM[str]+"點以上的戰術運用技能才能使用這種戰術。\n");
	  return 1;
	}

	if( str == "none" ) {
		this_player()->delete("tactic");
		write( "Ok.\n" );
		return 1;
	}

	if( !TACTIC_D(str)->can_use_tactic(this_player()) )
		return notify_fail("你現在還不會運用這種戰術。\n");

	this_player()->set("tactic", str);
	write( "Ok.\n" );
	return 1;
}

int help()
{
	write( @C_HELP
指令格式: tactic <方法>

這個指令用來設定在戰鬥所要使用的戰術，你所能用的戰術種類受你的戰術技能
限制，若是不使用戰術，則設為 none。
你所能使用的戰術如下:

berserk:	狂暴攻擊，增加破壞力而難以抵擋的攻擊戰術。
melee:		近身肉搏，兼顧攻擊與防禦，騎士的一貫戰術。
flank:		側面攻擊，面對強大敵人時用以自保的最佳戰略。
assault:	伺機突擊，殺手型人物的戰鬥方式。

你可以用 help xxx_tactic 到各種戰術進一步的說明。
如:
    help berserk_tactic

此外，某些戰術需要某些裝備才能使用。
C_HELP
	);
	return 1;
}
