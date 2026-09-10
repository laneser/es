#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "枯井中" );
       set_long( @C_LONG_DESC
你在一個枯井中，四周都是滿是青苔的井壁，由於長期的乾涸，整個
井底都是一條條的裂縫，想必井水是從其中的某些裂縫流出去的。
C_LONG_DESC
       );
       set("exits",([
           "out" : SAULIN"herb_field",
       ]) );
       reset();
}

void init()
{
        add_action( "explore_crack", "explore" );
        add_action( "pass_crack", "pass" );
}

int explore_crack()
{
    if( !(this_player()->query_quest_level("Tenshin's herb")) ) return 0;
    tell_object(this_player(),@ALONG
你小心的察探四周的井壁，發現其中有一個裂縫(crack)好像有生物
進出的痕跡....或許你可以穿過去(pass)看看。
ALONG
    );
    return 1;
}

int pass_crack(string arg)
{
    
    if( !(this_player()->query_quest_level("Tenshin's herb")) ) return 0;
    if( !arg || arg!="crack" )    
      return notify_fail( "通過什麼？\n" );
    tell_object(this_player(),
      "你用力一擠，竟然穿過裂縫到達另一個地方。\n" 
    );
    this_player()->move_player( SAULIN"under_well2", "SNEAK" );
    return 1;
}
