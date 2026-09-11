#include "mercury.h"
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川樓前庭" );
   set_long(@ANGEL
這裡是千川樓前庭，道路的兩旁種了一堆你從來都沒有看過的花，雖
然你沒看過，但是你知道那一定是一些高貴的品種，而路面是用這裡的特
產流晶巖做的，看起來閃閃發亮，讓人誤以為是用金子鋪成的．
ANGEL

   
         );
	set( "light",1);
	set_outside("eastland");		
	set( "objects", ([
	        "guard1":MOB"guard1",
	        "guard2":MOB"guard1",
	        ]) );
        set( "exits", ([
    "south" :MR"inn01",
    "north" :MR"inn03"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

