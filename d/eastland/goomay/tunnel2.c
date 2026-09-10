#include "goomay.h"

inherit ROOM;
int blocked;
void create()
{
        ::create() ;
	blocked=1;
        set_short( "地道" );
        set_long(
@LONG
這是一條窄窄的地道，你縮著身子只可以勉強的爬行前進，現在你
似乎已經到達這條地道的盡頭了，因為前面被大量的泥沙石頭掩埋了。
LONG
        );
	set("dig",1);
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
    if( arg=="forward" && !blocked)
	{
	if (blocked)
	{
	write(
		   "前面被堵住了，無法繼續前進。\n");
		return 1;
	}
	if (random(5)==3 )
		{
        write(
          "你努力的向前爬，終於看到一線天光，你趕快往亮處爬了出去 !!\n");
      this_player()->move_player( Goomay"house_brush", "SNEAK" );
        tell_room( Goomay"house_brush", 
         this_player()->query("c_name") + "在一陣灰塵之中從地底鑽了出來。\n"
        ,this_player() );

			return 1;
		}
	else
		{
        write( can_read_chinese() ?
          "你努力的向前爬，只見前面還是黑黝黝的一片，不知道還有多深。\n":
          "You climb forward but just see the darkness before you ! \n" );
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
void to_find_dig(string arg)
{
        object obj;

        if( !arg || (arg!="tunnel" && arg!="here" )) {
          write("這裡沒有你要挖的 ! \n");
          return;
	}
	if (!blocked)
	{
        write(
                   "地道已經打通了，你又繼續挖，想把地道挖寬一點。\n");
		return ;
	}
	if (random(6)==3 )
                {
        write( 
          "你用鏟子努力的清除堵住的砂石，累的滿身大汗，最後突然「轟隆」一聲，露出一個缺口 !!\n");
		blocked=0;
        set_long(
"這是一條窄窄的地道，你縮著身子只可以勉強的爬行前進，本來\n"+
"被堵住的部份現在似乎已經被打通，因為你感覺前面有清涼的微風吹\n"+
"來。\n");

                        return ;
}
        else
                {
	if (random(8)==2) {
        write(
          "你用鏟子努力的清除堵住的砂石，突然用力過猛，「拍」的一聲，鏟子斷了 !!。\n");
        if (obj = present ("shovel",this_player()))
          obj->remove();

                        return ;
	}
        write(
          "你用鏟子努力的清除堵住的砂石，累的滿身大汗，還是沒能打通。\n");
                        return ;
		}
}

void reset()
{
    ::reset();
    set( "blocked",1);
    blocked = 1;
}
