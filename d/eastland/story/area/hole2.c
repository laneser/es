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
是個安全的地方。北邊是禁地 (forbidden_ground) ，據說，需要具備經過天神祝
福的鎧甲才能安全無虞地通過。
LONG
	);
        set( "exit_suppress", ({
          "nd","su"}) );
	set("exits", ([
            "southup" : SAREA"hole1",
          "northdown" : SAREA"spell1",
                 "su" : SAREA"hole1",
                 "nd" : SAREA"spell1"
        ]) );
        set("objects", ([
         "lion#1" : SMOB"lion1",
         "lion#2" : SMOB"lion1",
         "lion#3" : SMOB"lion1"
        ]) );          
	set("pre_exit_func",([
	 "northdown" : "do_north",
	        "nd" : "do_north"
	]) );
	reset();
}
int do_north()
{
   if ( present("white lion",this_object()) ) {
      write("\n玄天玉獅攔住了你的去路！\n\n");
      return 1;
   }
   if ( this_player()->query_temp("mounting") ) {
      write("\n請先下馬，以免發生危險。\n\n");
      return 1;
   }   
   return 0;
}