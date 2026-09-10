#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("空地");
        set_long( 
@LONG
你站在一片空地上，地上野草叢生，野草大約是你頭的高度，使你看不到四周
的景象。抬頭一望，晦暗不明的天空，烏雲團簇好似一隻只正在張牙舞爪的野獸，
野獸正惡狠狠地瞪著你，似乎要把你吃下腹。
LONG);
    set( "exits", ([
         "east":LAKE"village10"
    ]) );
    set( "objects", ([
        "vendor":LMONSTER"vendor1",
      "wanderer":LMONSTER"wanderer"
    ]) );    
    ::reset();
}
