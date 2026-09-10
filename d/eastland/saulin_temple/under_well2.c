#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "井中洞穴" );
       set_long( @C_LONG_DESC
你在一個井底的洞穴中，這洞看起來很乾淨，同時還有淡淡的香氣，又
不是花香，你實在分辨不出是什麼香味，嗯! 這裡住的一定是愛乾淨又懂生
活情調的生物。
C_LONG_DESC
       );
       set("exits",([
           "out" : SAULIN"under_well1",
       ]) );
       set("objects",([
            "bug1" : SAULIN_MONSTER"small_bug",
            "bug2" : SAULIN_MONSTER"small_bug",
            "bug3" : SAULIN_MONSTER"small_bug",
       ]) );
       reset();
}
void init()
{
        if ( this_player()) this_player()->set_explore("eastland#29");
}
