
#include "hawk.h" 

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
        set_short("神秘的房間");
        set("no_vision",1);
        set_long( @LONG_DESCRIPTION
呵呵....不用寫....大家都看不到。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "northwest" : HAWK"room3-4",
                "southwest" : HAWK"room3-5",
                "east" : HAWK"room3-1",
                        ]) );
        create_door("east","west",
                ([
                "keyword":({"blackdoor","door"}),
                "status":"closed",
                "c_desc":"一個黑色的門",
                "c_name":"黑玉門",
                "name":"black jade door",
                "desc":"a black jade door",
                ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str == "east" || str=="southwest" || str=="northwest" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(120);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "從高聳的絕壁上摔下來!\n"+
                "竟然沒死! 真是命大啊!\n",this_player());
        return 1;
}
