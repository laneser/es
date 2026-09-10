
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("山麓小徑");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
你很驚訝的發現這條曲折的山麓小徑，此處蔓草叢生，不像是人煙常駐
之處，但是你卻隱約的聽見有人交談的聲音從遠方傳來，在山谷中輕輕的回
湯著，然而你無法很清楚的瞭解這聲音是從何而來，也許是風聲，也許是蟲
鳥叫吧? 你向身旁望去，發現一個小小的石頭(stone) 上似乎刻了幾個字。
LONG_DESCRIPTION
        );
        set("objects", ([
		"woman" : MOB"crying" ]) );
	set( "exits", ([
                "northeast" : HAWK"room1-2",
                     ]) );
         set("c_item_desc",([
                "stone":"@@to_stone"
                        ]) );
    reset();
}//end of creat


void init()
{
        add_action("to_pray","pray");
}

string to_stone()
{
return "你看到石頭上刻了幾個歪歪的字，不過你依然可以辨認出來...\n\n"+
    "入山者請注意~~~~此路有去無回~~~~\n              "+
        "想回頭者~~~~請誠心向上天~~~祈禱~~~吧。\n\n";
}

int to_pray()
{
        tell_object(this_player(),"你誠心的祈禱，忽然覺得一隻大手把你抓了起來。\n");
        this_player()->move_player(HAWK"altar2","SNEAK");
        return 1;
}

