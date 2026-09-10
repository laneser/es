
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("秘密小徑");
        set_light(1);
        set_long( @LONG_DESCRIPTION
小路繼續沿伸著，而且彎彎曲曲頗不好走，從遠方漸漸傳來山嵐的
呼嘯聲，還隱隱約約彷佛可以聽到幾聲淒厲的鳥叫聲，不過因為距離的
關係，你無法分辨出是什麼聲音。再次提醒你，要注意腳邊，否則摔入
懸崖之下不死也是去掉半條命喔。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "southeast" : HAWK"room1-5",
        "northwest" : HAWK"room1-3",
                        ]) );
        set("objects", ([
                "bug" : MOB"bird"
                        ]) );

    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southeast" || str =="northwest")
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
