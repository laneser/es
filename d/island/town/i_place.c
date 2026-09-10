#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("蜥蜴人領事館");
     set_long(@C_LONG
這兒是蜥蜴人的駐外辦事處，在此設辦事處的主要目的是為了增進該
族與外界的聯繫，協助有意開發其生活區的發展；但是，最主要的目的不
外乎是想利用這兒豐富的資訊來偵查魔族及武士堡的最新動態！
C_LONG
             );
     set("light",1);
     set("exits",([
               "north"  : ITOWN"square06"
            ]) );
     set("objects",([
               "lady"  : IMON"lady" ]) );
     reset();
#include <replace_room.h>
 }