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
全的地方。
LONG
	);
        set( "exit_suppress", ({
            "nd","su"}) );
        set("pre_exit_func",([
          "northdown" : "do_northdown",
                 "nd" : "do_northdown"
        ]) );
	set("exits", ([
            "southup" : SAREA"spell2",
          "northdown" : SAREA"spell4",
                 "su" : SAREA"spell2",
                 "nd" : SAREA"spell4"
        ]) );
        set("objects", ([
         "dragon" : SMOB"dragon1"
        ]) ); 
	reset();
}
void init()
{
   add_action("do_auction","auction");
}
int do_northdown()
{
   if ( present("thunder dragon",this_object()) ) {
      write("\n應龍阻止你向北而行！\n\n");
      return 1;
   }      
   return 0;
}
int do_auction(string arg)
{
   write("\n這裡忽然起了陣咒語，令你無法專注於拍賣動作！\n\n");
   return 1;
}