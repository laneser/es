#include "mercury.h"
inherit ROOM;

void create()
{
   ::create();
   set_short( "市場" );
   set_long(@ANGEL
這裡有是市場較為安靜的角落，和前面的熱鬧比起來，這裡顯得
安靜了很多，北邊是一間旅店，而東邊原本是是一間小商店但因經營
不善已倒閉．
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "north":MR"mar09",    
    "west" :MR"mar02",
                ]) );                   
         reset();                     
#include <replace_room.h>
}

