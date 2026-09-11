#include "mercury.h"

inherit ROOM;

void create()
{
   ::create();
   set_short( "碉堡" );
   set_long(@ANGEL
你走進一個小型的碉堡，四周圍的牆壁都是用見堅硬的石塊所築成的，擁
有完善的防禦力，裡面還有一個樓梯可以通往嘹望臺．
ANGEL
   
         );
	set( "light",1);		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "east"  :MR"road4",
    "up"  :MR"ca4",
                ]) );
         reset();                     
#include <replace_room.h>
}

