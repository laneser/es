//#pragma save_binary

// _time.c
// Returns the time and date in game units not in real time.
// Moby, 6-29-93
// Annihilator, 1-24-94

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON ;

int cmd_time()
{
	write( 
		WEATHER_D->query_c_game_time()+"\n");
	return 1 ;
}

int help() {
        write(@HELP
使用格式: time

顯示運行時間，但以遊戲時代時間為時間單位.
HELP
                );
        return 1;
}
