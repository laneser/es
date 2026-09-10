
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("稻田");
        set_long( @C_LONG_DESCRIPTION
你現在正走在海威鎮的南方的稻田裡，此處現今是一片綠油油的稻草，風一吹來
草隨風四處搖曳，不過此刻田中一片泥濘，走在此處你要萬分小心以免濺的滿身泥擰
在這一大片田中的一角, 長滿了一叢茅草。
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/d/eastland/haiwei/cornfield", 
                "west" :  "/d/eastland/haiwei/cornfield4",
            "east" :  "/d/eastland/haiwei/cornfield5"
           ]) );
        set("objects",([
            "rabbit":"/d/noden/elf/monster/rabbit"]));   
        reset();
}

void init()
{
      add_action("do_search","search") ;
      add_action("do_enter","enter") ;
}

int do_search(string arg)
{
    object player ;
    player = this_player() ;
    
    if(!wizardp(player)) 
        { player->set("action_points",player->query("action_points")/5+1) ;
        
         }
    write("在你專注於找尋的時候,你突然失神滑了一跤,跌進田中。\n") ;
    tell_room(this_object(),player->query("c_name")+
              "突然跌進田□,摔了個滿身泥巴。\n",player) ;     
    if(!arg || ( arg != "茅草" && arg != "reed"))
           return notify_fail("你找了又找，並沒有發現任何東西。\n") ;
    player->set_temp("beggar_enter",1) ;
    write("在你掙扎著要爬起來時看到在茅草那似乎有個入口。\n") ;
    
    return 1 ;
}

int do_enter(string arg)
{
    if(!arg || arg!="entrance" || !this_player()->query_temp("beggar_enter"))
         return 0 ;
      
    write("果不出所料,在撥開茅草後, 一座小村落霎時映入你的眼簾。\n\n") ;
    this_player()->delete_temp("beggar_enter") ;
    this_player()->move_player("/d/eastland/beggar/area/cross",
                   ({"","%s從村子外走了進來。\n"}),) ;    
    return 1 ;
}
