
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("貧民窟");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
越往貧民窟裡走，越覺得有一股死亡的氣息瀰漫在四周，對未來的絕望
和對過去的緬懷使得這些居住在貧民窟的鳥人們越來越不滿。你發現到路旁
有一間破破的小屋，相對之下算是滿乾淨的，你想要進去看看嗎?
LONG_DESCRIPTION
        );
        set( "exits", ([
        "southeast" : HAWK"room1-15",
        "northwest" : HAWK"room1-13",
           ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_enter" ,"enter");
}

int to_enter(string s)
{
        if ( s!= "house") return 0;
        this_player()->move_player(HAWK"room1-20","SNEAK");
        return 1;
}

