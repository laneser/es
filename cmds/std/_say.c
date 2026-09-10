//#pragma save_binary
#include <mudlib.h>
inherit DAEMON;

int cmd_say(string str)
{
	if (!str) {
	write("你自言自語.\n");
	say( this_player()->query("c_name")+"自言自語的不知道在說什麼.\n");
	return 1;
	}
	printf( "你說道：%s\n",str);
	say( this_player()->query("c_name") + "說道：" + str + "\n");

	return 1;
}
 
int help()
{
	write ( @HELP
使用格式: say <信息>

說話，所有以你同一場景的人都可聽見，有時是解謎的手段之一.
HELP
	);
	return 1 ;
}