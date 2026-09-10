
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("通往軍營的小路");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
你可以看到許多軍營 (military building)矗立在小路的兩旁，往南是鳥
人族老人們和聚居的地方。似乎還有一棟高高的建築物，不知道是啥東東。不
過你可能可以從旁邊的樓梯爬上去看看。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "south" : HAWK"room1-13",
        "east" : HAWK"room1-11"
              ]) );
        set("c_item_desc",([
                "building":"這是一棟不怎麼顯眼的軍營，但是隱約可以聽到練兵的吆喝聲。\n",
                        ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_climb","climb");
}

int to_climb(string s)
{
        if ( (s != "ladder") && (s != "樓梯") ) return 0;
        tell_room(environment(this_player()),
                "你看到"+this_player()->query("c_name")+
                "像烏龜一樣沿著樓梯慢慢往上爬!\n",this_player());
        this_player()->move_player(HAWK"room1-19","SNEAK");
        return 1;
}
