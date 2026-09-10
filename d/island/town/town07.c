#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("映世村大街");
     set_long(@C_LONG
這是映世村連外的的主要通道之一，再往西就是村落的廣場，那兒就
是謫仙島最繁榮的地方，如果你有任何需要，應該都可以在那兒找到。在
西方的不遠處，有一幢非常顯眼的白色建築，那就是和平紀念堂，來這裡
觀光的人，都應該去那兒逛一逛。
C_LONG
             );
     set_outside("island");
     set("light",1);
     set("exits",([
             "eastdown" : ISLAND"8,7.island",
                "west"  : ITOWN"town08"
            ]) );
     reset();
#include <replace_room.h>
 }
