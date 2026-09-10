#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("漁村道路");
        set_long( 
@LONG
你正走在漁村的道路上，迎面撲來的是一股濃濃的腥臭味；在地上，縱橫交錯
著血水枯乾的小河；一團團蒼蠅，正汲汲於腐爛的魚肉上，不時發出嗡嗡地鳴聲。
晦暗不明的天空，烏雲團簇好似一隻只正在張牙舞爪的野獸，野獸正惡狠狠地瞪著
你，好像對著你說：『快來吧，快來吧，我的食物』。西邊有間茅屋，北和東邊是
漁市場。
LONG);
    set( "exits", ([
         "south":LAKE"village17"
    ]) );
    set("objects", ([
       "merchant#1":LMONSTER"merchant",
       "merchant#2":LMONSTER"merchant",
       "merchant#3":LMONSTER"merchant",
    ]) );
    ::reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if ( !arg || arg!="house" )
       return notify_fail("你要進入那裡?\n");
   this_player()->move_player(LAKE"house18",({
       "%s進入了一間小茅屋。\n",
       "%s從外面走了進來.\n"}),"");
   return 1;
}