#include "../tsunami.h"
#include "anthill.c"

inherit ROOM;
void create()
{
    ::create();
    set_short("瀑布頂端");
    set_long(@LONG
這兒再往東走一些，就是最高點了；原來瀑布頂端的那一頭是一個大懸崖。
LONG
            );
    set_outside("island");
    set("exits",([
        "east":AREA"h2"]) ); 
    reset();
}

void init()
{
    add_action("do_search","search");
    add_action("do_climb","climb");
}

int do_search()
{
      tell_object(this_player(),
      "嗯～～！根據你推斷的結果，確信這裡有攀爬(climb)過的痕跡.......\n");
      return 1;
}

int do_climb( string arg)
{
    if( !arg || arg=="" )
      return notify_fail("你要爬哪個方向呢？\n");
    if( arg != "down" )
      return notify_fail("這裡就是瀑布的頂端了，你要往哪兒爬呢？\n");
    if( arg == "down" )
      to_climb_down( this_player(), AREA"in2", AREA"in", 35, 15);
    return 1;
}
