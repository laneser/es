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
	set( "objects",([
    "merchant":MOB"merchant"
            ]));			
        set( "exits", ([
    "west":MR"mar04",    
    "south" :MR"mar06"
                ]) );                   
         reset();                     
#include <replace_room.h>
}

