//#pragma save_binary

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON;

int help();

int cmd_force(string str)
{
	if( !str ) return help();
	if( !this_player()->query("max_fp") )
		return notify_fail("你有內力嗎 ?\n");

	if( str == "on" ) {
		this_player()->set_temp("enable_inner_force", 1);
		write("你決定在戰鬥中消耗內力以增加戰鬥能力。\n");
		return 1;
	}   

	if( str == "off" ) {
		this_player()->delete_temp("enable_inner_force");
		write("你決定在戰鬥中不使用內力以節省你的內力消耗。\n");
		return 1;
	}
	return help();
}

int help()
{
write( @C_HELP
		
指令格式: force [on|off]
 
這個指令讓你用來設定在戰鬥中是否消耗內力以增加戰鬥能力。

C_HELP
		);
    return 1;
}
