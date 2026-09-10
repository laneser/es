#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("魔族通關衙門");
     set_long(@C_LONG
這兒是樹雷王家的駐外辦事處，在此設衙門不但可以為過往商旅辦通
關手續，以應因魔族目前的戒嚴時期；更可就近監視蜥蜴人領事館及武士
校場的一舉一動！
C_LONG
             );
     set("objects",([
             "elder" : IMON"elder"
                   ]));         
     set("light",1);
     set("exits",([
               "west"  : ITOWN"square08"
            ]) );
     reset();
#include <replace_room.h>
 }