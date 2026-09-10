
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The road of the dwarf village","矮人村落的小路");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村莊的環莊道路上,這裡有著非常和平安詳的氣氛,恍佛是一個世
外桃源.這裡已經多年沒有戰爭了,矮人們的童年幾乎在此渡過. 西邊的建築是你在矮人
度裡看過最華麗,最優美的建築,但是似乎有股魔力阻擋你進入.
CLong
    );
    set("exits",([
                "west":Deathland"/village/vr7",
                "north":Deathland"/village/v15",
                "south":Deathland"/village/v13",
             ]));
    set("pre_exit_func",([
                "west":"to_pass",
                ]) );
    set("objects",([
        "bard":Monster"/bard02",
         ]) );
    ::reset();
}

int to_pass()
{
   if ( !(this_player()->query_temp("deathland_magicwall")) ) {
     write("一道魔法牆阻擋住你的去向.\n");
     return 1;
     }
   else {
     write("由於你的身體有著一股神奇的力量,你輕易的通過魔法牆.\n");
     return 0;
     }   
}
