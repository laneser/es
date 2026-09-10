#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "快意堂" );
        set_long(
@LONG
這裡是本鎮最大的賭坊，只聽到一陣陣呼蘆喝雉之聲，鱉十板凳喊的
通天價響，穿插著幾聲「洗拔辣」，真是亂的一榻糊塗。快意堂名義上是
暴發戶錢不多的產業，事實上卻是由某幫會託管，所以這裡除了偶而爭錢
鬥毆的小事外，一向沒有大案發生，不過捕快們還是很樂意常常來走走，
補貼補貼微薄的薪水。
LONG
        );
        
        set( "exits", ([
                "north" : Goomay"kwi_yi2",
		"south" : Goomay"row15",
        ]) );
        
        set( "objects", ([
                "gambler1" : Mob"gambler",
                "gambler2" : Mob"gambler",
                "gambler3" : Mob"gambler",
                "gambler4" : Mob"gambler",
                "guard1"   : Mob"body_guard",
                "guard2"   : Mob"body_guard",
        ]) );
        set( "pre_exit_func", ([
                "north" : "can_pass" ]) );
        reset();
}

int can_pass()
{
	if (present("bodyguard",this_object()) && !wizardp(this_player()))
	{
		tell_object(this_player(),
		"保鏢擋在你面前說道：「堂主正在喝酒 !! 不喜歡有人打擾 !!」\n");
	return 1;
	}
	else
        return 0;
}
