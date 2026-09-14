#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
你來到了一處黑暗的洞穴，這裡空洞洞地似乎沒有任何東西。除此之外，你感
到這裡非常潮溼，空氣中還有些發黴的味道，讓你混身感到不舒服。在這裡，不時
聽到些動物的嘶吼聲，其聲可怖已極，更兼在地上看到一堆骸骨，說明了這實在不
是個安全的地方。西邊是禁地，據說，需要具備經過天神祝福的鎧甲才能安全無虞
地通過。
LONG
	);
        set( "exit_suppress", ({
           "nd"}) );
                  
	set("exits", ([
          "east" : SAREA"hole1",
          "west" : SAREA"spell1"
        ]) );
	reset();
}
