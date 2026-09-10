//#pragma save_binary

/*
// The "brief" command.
// toggle your verbosity.
// Part of the TMI mudlib, of course!
// Written by Buddha(2-19-92)
*/

#include <mudlib.h>

inherit DAEMON ;

int cmd_brief()
{
	int brief;
	brief = (int)previous_object()->query("brief");
	if(brief) {
		write("Verbose mode.\n");
		this_player()->set("brief", 0);
	} else {
		write("Brief mode.\n");
 		this_player()->set("brief", 1);
	}
	return 1;
}

int help()
{
	write ( @HELP
使用格式: brief

設定移動時所看到場景描述的詳細程度.
如果對地區很熟悉或想加快網絡速度，可以開啟此功能.
HELP
	);
	return 1 ;
}
