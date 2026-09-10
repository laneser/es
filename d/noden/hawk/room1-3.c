
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("秘密小徑");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
你嚇然發現到在那絕壁之後，竟隱藏有這麼一條小徑，你不禁讚歎
起造出此一秘密小徑的生物。不過奇怪的是，小徑造得相當粗糙，讓你
走起來覺得頗不舒服，不知道是為了什麼。此外，這條位在峭壁邊的小
徑也不寬敞，最好是注意一下你的腳步，掉到山下可不是一件好玩的事
唷！
LONG_DESCRIPTION
        );
        set( "exits", ([
        "southeast" : HAWK"room1-4",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southeast" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(70);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "從高聳的絕壁上摔下來!\n"+
                "竟然沒死! 真是命大啊!\n",this_player());
        return 1;
}
