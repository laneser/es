//#pragma save_binary

// uptime.c
// Tells you how long the mud is up.
// Lord knows who wrote it.
// Mobydick added header and help, 11-20-92

#include <mudlib.h>
#include <reboot.h>

inherit DAEMON;

int cmd_uptime()
{
	printf("東方故事已經連續執行了 %s，\n", format_c_time(uptime(), 1));

	if( REBOOT_DELAY-uptime() > 0 )
	printf("離 Reboot 還有 %s。\n",format_c_time(REBOOT_DELAY-uptime(), 1) );
	else
	  this_player()->quick_message("已經進入 Reboot 倒數計時了。\n" );
	return 1;
}

int help()
{
	write (@HELP
使用格式: uptime

顯示遊戲已經運行多少時間.
HELP
);
	return 1;
}
