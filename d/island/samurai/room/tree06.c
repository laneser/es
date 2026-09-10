#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "林間小徑" );
   set_long(@ANGEL
你走在櫻花樹林中的小徑上，道路的兩旁都是盛開的櫻花樹，飄落的櫻花在
你面前飛舞著，構成一幅美麗的景色，也不知道他們是怎麼種的，這些櫻花樹居
然能保持四季都開著花，或許這是一種東方的神秘吧！
ANGEL

   
         );
	set_outside("eastland");		
        set( "exits", ([
    "south"  :MR"tree02",
    "north"  :MR"tree07"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

