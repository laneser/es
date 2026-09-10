
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("內城入口");
        set_light(1);
        set_long( @LONG_DESCRIPTION
和一般的城不一樣的是，天空之城是整個飄浮在天空中的，身處在雲霧
之間，讓你感到有如到了仙境。你仔細往四周瞧瞧，這才發現鳥人族的人民
大部份都是在天上飛來飛去，鮮少有在地上活動的，原來天空之城的內城才
是鳥人族主要的活動區，外城則是為防範敵人而建。
    抬頭向上望，內城正在你的頭頂上飄啊飄的。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "west" : HAWK"room1-10",
        "north" : HAWK"room1-8",
        "up" : HAWK"room2-15",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="west" || str=="north" || str=="up" )
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
