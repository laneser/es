
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("競技場");
        set_long( @LONG_DESCRIPTION
這裡是鳥人族每年比武大會舉行的地點，你可以看到四周空蕩蕩的啥都
沒有，正是比武的好地方。不過，你卻發現現在有點不一樣，觀察一下，你
似乎覺得四周隱隱約約傳來野獸的咆嘯及低聲嘶吼的聲音，看來，你得要自
求多福羅。如果想要回頭的話，這裡有條粗粗的繩索(rope)可以讓你往上爬
(climb) 。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "east" : HAWK"square2",
        "south" : HAWK"square4",
                     ]) );
    reset();
}//end of creat


void init()
{
        add_action("to_climb","climb");
}

int to_climb(string str)
{
        if ( !str || str != "rope") return 0;
        tell_object(this_player(),@LONG
你沿著繩索慢慢往上爬。
LONG
        );
        this_player()->move_player(HAWK"room3-4","SNEAK");
        return 1;
}
