#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("武士戰鬥教練場");
     set_long(@C_LONG
這兒是武士堡的戰鬥教練場，美其名為教練場，實際上，它卻是武士
堡用來埋藏軍隊的偽裝，為的是就近監視蜥蜴人及魔族的動向；一旦有些
許的風吹草動，那麼一場驚天動地的殺戮恐怕就無法避免了
C_LONG
             );
     set_outside("island");
     set("light",1);
     set("exits",([
               "south"  : ITOWN"square02"
            ]) );
     reset();
#include <replace_room.h>
 }
