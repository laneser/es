#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
這裡是禁地裡面的洞穴，空洞洞地似乎沒有任何東西。除此之外，你感到這裡
非常潮溼，空氣中還有些發黴的味道，讓你混身感到不舒服。在這裡，不時聽到些
動物的嘶吼聲，其聲可怖已極，更兼在地上看到一堆骸骨，說明了這實在不是個安
全的地方。南邊是禁地，據說，需要具備經過天神祝福的鎧甲才能安全無虞地通過
。
LONG
	);
        set( "exit_suppress", ({
            "nd","su"}) );
	set("exits", ([
            "southup" : SAREA"spell1",
          "northdown" : SAREA"spell3",
                 "su" : SAREA"spell1",
                 "nd" : SAREA"spell3",
        ]) );
        set("objects", ([
         "dog#1" : SMOB"dog1",
         "dog#2" : SMOB"dog1",
         "dog#3" : SMOB"dog1",
        ]) );
	reset();
}
void init()
{
   add_action("do_auction","auction");
}
int do_auction(string arg)
{
   write("\n這裡忽然起了陣咒語，令你無法專注於拍賣動作！\n\n");
   return 1;
}