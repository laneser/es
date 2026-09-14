#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("洞穴");
	set_long(@LONG
你來到了一處黑暗的洞穴，這裡空洞洞地似乎沒有任何東西。除此之外，你感
到這裡非常潮溼，空氣中還有些發黴的味道，讓你混身感到不舒服，或許爬上去（
climb up )會令你好過一點。
LONG
	);
        set( "exit_suppress", ({
          "nd"}) );
	set("exits", ([
          "northdown" : SAREA"hole2",
                 "nd" : SAREA"hole2"
        ]) );
	reset();
}
void init()
{
   add_action("do_climb","climb");
}
int do_climb(string arg)
{
   if ( !arg || arg!="up" ) return notify_fail("Syntax : <climb up> \n");
   this_player()->move_player(SAREA"plain3",({
         "%s爬了上去。\n",
         "%s北邊的小洞爬了上來。\n"}),"");
   return 1;
}