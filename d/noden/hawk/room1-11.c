//room1-11.c
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("外城小徑");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
    走在外城的小徑上，遠眺著你剛剛走來的小徑，回想起剛剛步步驚
魂的情景，以及那蜿蜒崎嶇的山路，你覺得似乎很難會有敵人能夠入侵
吧，不知道鳥人們在怕些什麼，問問這裡的老人們或許可以得到一些消
息吧。往西走就可以到達士兵們居住的軍營，你可以看到三五成群的士
兵們在這附近巡邏著。
LONG_DESCRIPTION
        );
        set( "objects", ([
                "soldier1" : MOB"warrior",
                "soldier2" : MOB"warrior",
                "soldier3" : MOB"warrior"
                        ]) );
        set( "exits", ([
        "west" : HAWK"room1-12",
        "north" : HAWK"room1-10",
                ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="west" || str=="north" )
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
