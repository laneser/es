#include "hawk.h"
inherit ROOM;
void create()
{
        ::create();
        set_short("內城小徑");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
行走在幽靜怡人的內城小徑，你可以察覺得到路邊的植物也都有經過精心
照顧，環境有夠好。三三兩兩的鳥人族小朋友在這邊嘻鬧，也為剛肅的天空之
城增添了一些活潑的氣氛，頓時讓你覺得遠離喧囂的感覺真好，有點樂不思蜀
的感覺。
LONG_DESCRIPTION
        );
        set( "objects", ([
                "boy1" : MOB"boy.c",
                "boy2" : MOB"boy.c",
                "girl" : MOB"girl.c",
                        ]) );

        set( "exits", ([
                "southwest" : HAWK"room2-4",
                "north" : HAWK"room2-7",
                        ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southwest" || str =="north")
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
