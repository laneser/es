#include "forest.h"
 
inherit ROOM;
 
void create()
{
  ::create();
  set_short("黑森林一角");
  set_long(@CLong
這裡是黑森林的一角, 比較特別的是, 這邊有著一點點的光亮。光穿
過密林中的隙縫, 照出一條小徑。而在小徑的末端, 一個略為突起的小平
臺(plate) 在黑暗中發著光, 向你招著手。
CLong
        );
        set("exits",([
        "west"      : HERE"3n2w",
        "southeast" : HERE"2n",
        "plate"     : RUIN"plate",
    ]));
//        set("pre_exit_func", ([
//                "plate" : "go_plate",
//        ]) );
    set("objects", ([ "ammunt" : MOB"ammunt", ]) );
        set("exit_suppress", ({ "plate", "west", }) );
//        set("exit_msg", ([
//                "plate" : "@@go_plate",
//        ]) );
        ::reset();
}
 
void init()
{
        add_action("to_look", "look");
        add_action("go_plate","plate");
}
 
int to_look(string arg)
{
        if( arg != "plate" ) return 0;
        write("從這邊看過去那塊平臺似乎不大, 不過去那裡看看應該會有所幫助才對。\n");
        return 1;
}

int go_plate()
{
        tell_room( environment(this_player()),
                this_player()->query("c_name")+"向那塊平臺走去。\n"
                , ({this_player(),this_object()}) );
        this_player()->move_player(RUIN"plate","SNEAK");
        return 1;
}

