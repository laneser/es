#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("映世村廣場");
     set_long(@C_LONG
這兒就是映世村最著名的廣場，地上鋪著一片片的大石板，穿插著幾
株新植不久，剛發新葉的榕樹，走在這兒，不禁讓人心情放鬆。在廣場的
中間，佇立著一幢白色亮晶晶的建築物，沒錯，這就是遠近著名的和平紀
念堂。如果你來到這兒，卻忘了進去參觀，那麼，你一定會後悔的哦！
C_LONG
             );
     set_outside("island");
     set("light",1);
     set("exits",([
                 "east" : ITOWN"square05",
               "north"  : ITOWN"square03"
            ]) );
     reset();
#include <replace_room.h>     
 }