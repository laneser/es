#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川樓二樓" );
   set_long(@ANGEL
在你來到千川樓二樓，這裡的構造和一樓比起來大致相同，只是通道變窄了
許多，據說這是為防止敵人大量入侵而設計的，地板改成用較易發出聲音的木材
做成，只要有人一進入二樓，其發出的聲音一定會被在二樓守衛的武士們聽見，
空氣中還飄有一股黑檀木的香氣．
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "west"  :MR"inn2-5",    
    "south" :MR"inn2-2",
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

