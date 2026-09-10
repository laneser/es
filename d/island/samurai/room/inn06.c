#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川樓一樓" );
   set_long(@ANGEL
在你來到千川樓一樓，其內部的裝潢都是名家精心設計的，不管是支撐
的樑柱，還是照明的燈具，都是用上等的建材加上工匠們全心全意的雕塑所
製成的，地板則是用高級的木材做成的，走起來和外面的石頭路面有著不一
樣的感受，空氣中還飄有一股黑檀木的香氣．
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "west"  :MR"inn04",    
    "east" :MR"inn07",
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

