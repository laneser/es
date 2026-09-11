#include "mercury.h"
inherit ROOM;

void create()
{
   ::create();
   set_short( "中央廣場" );
   set_long(@ANGEL
在你的面前是一個寬大的大廣場，其位置可說是此城堡的中央，向西
可以前往武士訓練場，向東則可以前往市場，而往北一直走下去可以到武
士指揮中心～千川樓～．
ANGEL

   
         );
	set( "light",1);	
	set_outside("eastland");	
        set( "exits", ([
    "west"  :MR"tra01",
    "east"  :MR"cac08",    
    "south" :MR"cac06"
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

