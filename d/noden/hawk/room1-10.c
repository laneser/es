
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("外城小徑");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
自從幾年前一場大戰之後，鳥人族就退守到天空之城，而為了避免敵
人再度入侵，鳥人們做了許多防範的工事，將天空之城外又加蓋了一小城
，也就是現在你所在的外城。
    在外城居住的有兩種人，一種是負責守衛天空之城的士兵們，另外就
是一些比較窮和年老無依的鳥人們，他們就住在外城的貧民窟裡。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "east" : HAWK"room1-9",
        "south" : HAWK"room1-11",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="east" || str=="south" )
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
