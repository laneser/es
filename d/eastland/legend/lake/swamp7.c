#include "../legend.h"

inherit ROOM;
inherit LAKE"in_swamp";

void create()
{
object toad;
        ::create();
    set_short("沼澤");
        set_long( 
@LONG
啊！毒氣，糟糕，你走進了最危險的沼澤地，四周都是足以致命的瘴氣。但是
奇怪的是，這裡不像其他沼澤地充滿各式各樣吃人的巨型怪物，也沒有人類的□骨
，相反的，這裡到處都是巨型沼澤怪獸的殘骸。莫名的肅靜，空氣中除了瀰漫著一
股濃厚的血腥惡臭之外，更有一種令人毛骨悚然，心驚肉跳的感覺；一種似乎你已
經不是活人的感覺。
LONG
    );
    set( "exit_suppress", ({
        "east","south","west","north","southwest" }) );
    set("exits",([
            "east":LAKE"swamp6",
            "west":LAKE"swamp4", 
           "south":LAKE"swamp2",
           "north":LAKE"swamp5",
       "southwest":LAKE"swamp8",
       ]) );
       toad = new(LMONSTER"redtoad");
       toad->move(this_object());
        
       reset();
}
int clean_up()
{
       return 0;
}

