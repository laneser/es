#include "../tsunami.h"
#include "anthill.c"

inherit ROOM;
void create()
{
    ::create();
    set_short("瀑布內側");
    set_long(@LONG
原來瀑布後頭還有一點點可以容身的地方，經年累月的沖蝕使得岩石變
得光滑，而且長滿了苔蘚；你可以確信的是，這地方似乎不是天然形成的。
LONG
            );
    set("light",1);
    set_outside("island");
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
    if( arg != "up")
      return notify_fail("這裡就是瀑布的下方了，你還想往哪兒爬呢？\n");
    to_climb_up(this_player(),AREA"in1",40);
    return 1;
}
