//#pragma save_binary
 
//	File	:  /cmds/ghost/_tell.c
//	Creator	:  Watcher@TMI  (04/03/93)
//
//	Just a filler tell command for the ghosts.

#include <mudlib.h>

inherit DAEMON ;
 
int cmd_tell()
{
	write( can_read_chinese()?
		"你現在的狀態沒有足夠的能力傳達訊息給任何人，如果你要報告\n"
		"程式的 bug ，請用 wizcall 指令。\n":
		"As a ghost, you do not have the strength to tell anyone.\n"
		"If it is an error report, you may use the \"wizcall\" command.\n");
	return 1;
}

