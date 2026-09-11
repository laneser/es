#include "mercury.h"
inherit ROOM;

void create()
{
   ::create();
   set_short( "市場警衛室" );
   set_long(@ANGEL
這是市場警衛所居住的地方，雖然有一點雜亂，但整體上大致還算乾
淨，在牆角邊放著一個武器架，而牆上則是記錄著本月的物價情形．
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
    "guard1":MOB"market_guard",
    "guard2":MOB"market_guard"
            ]));			
        set( "exits", ([
   "south" :MR"mar02"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

