#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set_short("地道" );
        set_long(
@LONG
這是一條窄窄的地道，你縮著身子只可以勉強的爬行前進，這條
地道不知道有多長，也不知道另一端是通往哪裡。
LONG
        );
        
        reset();
}

void init()
{
    add_action("to_climb", "climb");
}
int to_climb( string arg )
{
    if( !arg || (arg != "backward" && arg !="forward") )
      return notify_fail("Climb backward or forward ?\n");
    if( arg=="forward" )
	{
	if (random(6)==3 )
		{
        write(
          "你努力的向前爬，終於到了洞口的一端，但是出口已經被一大堆泥土封住了 !!\n");
      this_player()->move_player( Goomay"tunnel2", "SNEAK" );
        tell_room( Goomay"tunnel2", 
         this_player()->query("c_name") + "在一陣灰塵之中從地道那端爬出來。\n"
        ,this_player() );

			return 1;
		}
	else
		{
        write(
          "你努力的向前爬，只見前面還是黑黝黝的一片，不知道還有多深。\n");
			return 1;
		}
	}
        write( 
          "你決定退出地道，一路倒著爬出地道。\n");
      this_player()->move_player( Goomay"jail_room2", "SNEAK" );
        tell_room( Goomay"jail_room2", 
         this_player()->query("c_name") + "在一陣灰塵之中從地洞中鑽了出來。\n"
        ,this_player() );

    return 1;
}
