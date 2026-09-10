#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("城中心");
	set_long( @LONG
你站足之地是「巫咸國」的中心點，地上是用玉做的，並且在其上還雕刻著龍
鳳之類的祥瑞動物。在城中心的旁邊還擺著一座高八尺的金鑄雕像，那雕像，栩栩
如生，一看就知道是經過行家之手，否則不會如此生動細膩。北邊是皇宮大道，南
邊本來是城裡最主要的道路，不曉得為什麼，被封閉起來。在路旁還有一塊黑色大
石(stone)。
LONG
	);
        set("light",1);
	set( "exits", ([ 
            "east" : SCITY"ne1",
            "west" : SCITY"nw1",
           "north" : SCITY"palace1"
        ]) );
        set( "c_item_desc", ([
                  "stone" : @LONG
一顆有著純黑色的大石，石頭上寫著黑色代表黑暗的意思，上面有被摸過(touch)的痕跡。
LONG
        ]) );
	reset();
}
void init()
{
   add_action("do_worship","worship");
   add_action("do_touch","touch");
}
int do_touch(string arg)
{
   if ( !arg || arg !="stone" )
       return notify_fail("你要摸什麼東西？\n");
   write("\n你好奇地摸一摸這塊黑色的大石，只見一道黑色的光線貫穿你的身子！\n\n\n");
   this_player()->move_player("/d/deathland/city/c1",({
       "%s的身子被一道黑色的光線貫穿！\n",
       "%s借著一道黑色來到了這裡.\n"}),"");
   write("\n在黑光之後，你被帶到了黑暗大陸。\n");
   return 1;
}
int do_worship()
{
    tell_object(this_player(),
       "你雙手合什，跪在地上向雕像虔誠地膜拜，希望今年能夠發大財。\n");
    this_player()->save_me();
       "/adm/daemons/backup"->user_backup(this_player());
    return 1;
}