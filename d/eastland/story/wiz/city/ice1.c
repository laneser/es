#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("冰原");
	set_long( @LONG
極目遠眺是片無垠無涯，銀光閃閃，通體晶瑩，不見任何塵沙的冰原。在這片
堅滑光潤的地面上，竟會生著許多不知名的奇樹，每株七、八抱寬，其高多達一、
二丈以上，全身覆蓋著一片冰衣，裡面卻是瓊枝碧葉，青蔥欲滴。在你旁邊還有個
十尺寬的小池子(pool)。
LONG
	);
	set( "exits", ([ 
           "north" : SCITY"ice2",
           "south" : SCITY"ice1",
            "east" : SCITY"ice1",
            "west" : SCITY"ice1",
        ]) );
	set("c_item_desc", ([
	   "pool":"一個直徑約十尺的小池子，池水呈綠色，如果你泳技夠，可以潛下(dive pool)去看看。\n" 
        ]) );
	reset();
}
void init()
{
    add_action("do_dive","dive");
}
int do_dive(string arg)
{
   string name;
   object player;
   if ( !arg || arg !="pool" ) return 0;
   player=this_player();
   name=this_player()->query("c_name");
   write("你雙手往前一伸，兩腳一蹬，撲向小池子而去！\n");
   tell_room(environment(player),sprintf(
     "%s往小池子潛了去下！\n",name),player);
   tell_object(player,@LONG


忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！
忽然，池底下一股強大的漩渦把你捲到別的地方處！



LONG   
   );
   player->move_player(SAREA"rest1.c","SNEAK");
   tell_object(player,"等你醒來時已經在一個涼亭裡了。\n\n");
   tell_room(environment(player),sprintf("%s從旁邊的蓮池裡爬了上來。\n",name),player);   
   return 1;
}
