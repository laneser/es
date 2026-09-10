
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("中央大道");
        set("light",1);
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
你繼續走在內城的道路上，觀察鳥人們所建築的房子，發現大部份比較雄
偉的屋子都是頗新的，而老舊的房子則都是破破爛爛的，但是還是很多人住，
而較新較好的房子反而空空蕩蕩，或許是鳥人天性喜歡住在比較簡陋的房子吧
....但不知道為什麼會多出這些新建築呢？在所有的房子當中，你注意到一間
特別漂亮的房子，想要進去(enter) 看看嗎？
LONG_DESCRIPTION
        );
        set( "exits", ([
        "northwest" : HAWK"room2-8",
        "south" : HAWK"room2-13",
                     ]) );
    reset();
}//end of creat

void init()
{
        add_action("to_enter","enter");
}

int to_enter(string str)
{
        if (str == "house" || str == "building")
        {
                this_player()->move_player(HAWK"traroom","SNEAK");
                return 1;
        }
        else
        {
                tell_object(this_player(),"你想進去哪裡??\n");
                return 1;
        }
        return 1;
}
