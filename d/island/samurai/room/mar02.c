#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "市場" );
   set_long(@ANGEL
這裡有許多人們聚集在此買賣物品，這就是武士城堡內的市場，雖說
這是武士堡內最熱鬧的地方，但是所賣的物品卻少的可憐，你如果想買一
些有用的東西，勸你還是別來這裡吧！
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "north":MR"mar03",    
    "west" :MR"mar01",
    "east" :MR"mar08",
    "south":MR"mar04"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

