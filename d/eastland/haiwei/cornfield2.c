
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("稻田");
        set_long( @C_LONG_DESCRIPTION
你現在正走在海威鎮的南方的稻田裡，此處現今是一片綠油油的稻草，風一吹來
草隨風四處搖曳，不過此刻田中一片泥濘，走在此處你要萬分小心以免濺的滿身泥擰
不過田的中央有一個小洞(hole)。
C_LONG_DESCRIPTION
        );
        set("layuter_hole",1);
    set("item_desc",([
        "hole":"這是一個又深又窄的洞穴，由此望去底下一片漆黑，你想或許可以爬下去(climb down)。\n"]));
        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "south" : "/d/eastland/haiwei/cornfield4",
            "east" :  "/d/eastland/haiwei/cornfield"
           ]) );
        set("objects",([
            "fox1":"/d/eastland/haiwei/monster/fox",
            "fox2":"/d/eastland/haiwei/monster/fox"]));   
        reset();
}

void init()
{
 add_action("do_climb","climb");   
}

int do_climb(string arg)
{
  if (!arg || arg!="down") return 0;
     write("這洞太深了你無法爬下去，你也許需要某些物品才有可能爬下去。\n");
     return 1;
    
 }
