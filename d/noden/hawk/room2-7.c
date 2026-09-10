
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("內城小徑");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
遠離了內城大道的喧囂和軍事緊張的氣氛，這裡是天空之城最安靜的地
方之一，許多年青的鳥人們，在一天緊張的生活之中，常會忙裡偷閒的到這
邊閒晃，不過，要是天雨路滑，你就要小心羅，從這要是往外掉，可是會摔
的不輕喔。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "northeast" : HAWK"room2-8",
        "south" : HAWK"room2-5",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="northeast" || str=="south" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(90);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "從高聳的絕壁上摔下來!\n"+
                "竟然沒死! 真是命大啊!\n",this_player());
        return 1;
}
