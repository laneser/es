#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "武士團隊長室" );
   set_long(@ANGEL
這裡是武士團隊長的住所，約修通常都在這裡思考武士團的大小事
務，除了約修外，其他人是一律不準進入三樓的，所以約修可以在此安
靜的好好思考及休息．
ANGEL

   
         );
	set( "light",1);
	set("objects",([
	"ya_shu":MOB"ya_shu"
	]));		
        set( "exits", ([    
    "south" :MR"inn3-1",
                ]) );
                            
         reset();                     
}

