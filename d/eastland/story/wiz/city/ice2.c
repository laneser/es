#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("冰原");
	set_long( @LONG
極目遠眺是片無垠無涯，銀光閃閃，通體晶瑩，不見任何塵沙的冰原。在這片
堅滑光潤的地面上，竟會生著許多不知名的奇樹，每株七、八抱寬，其高多達一、
二丈以上，全身覆蓋著一片冰衣，裡面卻是瓊枝碧葉，青蔥欲滴。另外在北邊還有
一個隆出地面約六尺高的小冰丘。
LONG
	);
	set( "exits", ([ 
           "north" : SCITY"ice2",
           "south" : SCITY"ice1",
            "east" : SCITY"ice2",
            "west" : SCITY"ice2",
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
   add_action("do_enter","enter");
}
int do_search(string arg)
{
   if (arg!="cave") {
      write("你找了找，發現北邊的冰丘竟然有一個小洞穴(cave)！\n");
      return 1;
   }
   write("這是一個尺寬的圓洞，如果你有膽量可以進去(enter cave)看看。\n");
   return 1;
}
int do_enter(string arg)
{
   if (!arg||arg!="cave")
     return notify_fail("你想要進去那裡？\n");
   write("你進入北邊冰丘的一個小洞穴裡。\n");
   this_player()->move_player(SCITY"ihole1",({
       "%s進入了冰丘的一個小洞穴。\n",
       "%s從外面走了進來.\n"}),"");
   return 1;
}