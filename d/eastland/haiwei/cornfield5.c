
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
        set_short("稻田");
        set_long( @C_LONG_DESCRIPTION
你現在正走在海威鎮的南方的稻田裡，此處現今是一片綠油油的稻草，風一吹來
草隨風四處搖曳，不過此刻田中一片泥濘，走在此處你要萬分小心以免濺的滿身泥擰
。
C_LONG_DESCRIPTION
        );

        set_outside( "haiwei" );
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/d/eastland/haiwei/cornfield3", 
                "west" :  "/d/eastland/haiwei/cornfield1",
           ]) );
        set("objects",([
            "fox":"/d/eastland/haiwei/monster/fox"]));   
        reset();
}
