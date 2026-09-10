#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "千川樓二樓警衛室" );
   set_long(@ANGEL
在你來到千川樓二樓警衛室，這是隨時都有人在此看守著，以防止
有人來行刺武士團隊長，而看守的人也都是武士團裡的精英，同時也是
對武士團絕對忠心武士．
ANGEL

   
         );
	set( "light",1);
	set( "objects",([
	    "guard1":MOB"guard4",
	    "guard2":MOB"guard4"
	    ]));		
        set( "exits", ([
    "east"  :MR"inn2-4",
    "north" :MR"inn2-6"    
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

