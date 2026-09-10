
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("天空之城城門");
        set_light(1);
        set_long( @LONG_DESCRIPTION
走到這裡，你以經可以清楚的看到天空之城高大的大門口了。你仔細端詳
著大門，發現竟是由最名貴的大理石所建，上面雕滿了許多飛禽走獸的圖樣，
真不知道這些共花費了多少人力才完成。往城門內一看，你發現到整個城其實
是浮在空中的，這時候你終於相信傳說中的天空之城是存在的。此外你也看到
了許多鳥人在城內飛來飛去，看來這個與世隔絕已久的城市大概可以說是鳥人
族的世外桃源。為預防敵人的入侵，在這裡也有數名鳥人族的戰士駐守。
LONG_DESCRIPTION
        );
        set("objects", ([
                "war" : MOB"fighter",
                "war1" : MOB"fighter"]) );

        set( "exits", ([
        "east" : HAWK"room1-7",
        "south" : HAWK"room1-9",
                    ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="south" || str=="east" )
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
