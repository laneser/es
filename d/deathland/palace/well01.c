
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("well","井底");
  set_long(@Long
Long
,@CLong
一個淺淺的井,而井裡的水也不是很深.井的四周長滿了青苔,似乎爬上去並不
是一件困難的事.
CLong
);

 set("objects",([
    "frog":Monster"/frog",    
 ]) );
    
::reset();
}

void init()
{
    add_action("to_climb","climb");
}

int to_climb()
{
    say(this_player()->query("c_name")+"爬出井底\n");
    write("你輕易的爬出井底\n");
    this_player()->set_explore( "deathland#8" );
    this_player()->move_player(Deathland"/palace/pa_07","SNEAK","");
    return 1;
}
