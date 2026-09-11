#include "mercury.h"
inherit DOORS;
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
    "east"  :MR"inn06",    
    "south" :MR"inn03",
    "north" :MR"inn05"
                ]) );
      create_door("south","north",([
                  "keyword" : ({"door","ebony door"}),
                  "status"  : "closed",
                  "name"    : "Ebony Door",
                  "c_name"  : "黑檀木門",
                  "c_desc"  : "一個用黑檀木做門，上面用精細的手工\n"
                              "雕出一條華麗的龍\n"
                  ]) );
                            
         reset();                     
}

