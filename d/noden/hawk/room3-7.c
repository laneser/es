
#include "hawk.h" 

inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short("神秘的房間");
        set("light",1);
        set_long( @LONG_DESCRIPTION
你走進這一間房間，映在你眼前的，除了白色，還是白色。彷佛空無一物，
又彷佛充滿了許多感受不到的奇妙物質。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "northeast" : HAWK"room3-8",
                "southeast" : HAWK"room3-9",
                "west" : HAWK"room3-1",
                     ]) );
        create_door("west","east",([
                "keyword":({"whitedoor","door"}),
                "status":"closed",
                "c_desc":"一個白色的小門",
                "c_name":"白玉門",
                "name":"white jade door",
                "desc":"a white jade door",
        ]) );
    reset();

}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str =="west" || str=="southeast" || str=="northeast" )
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
