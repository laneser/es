#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("叢林");
	set_long(@LONG
你來到了一處熱帶叢林區，四周滿是高及頭頂的蕨類植物，這裡的熱氣快要使
得你昏倒在地，更兼藏身在植物裡的小蟲，不住地叮著你的全身，令你難過已極！
或許，先找個清涼的地方休息一下，再繼續走，會好過一點。忽然，不遠的東邊傳
來陣陣野獸的叫聲，那聲音，駭人已極，你最好不要往那邊走去，以免發生危險。
LONG
	);
	set("exits", ([ 
       	    "east" : SAREA"coast5", 
            "west" : SAREA"coast3",
           "south" : SAREA"coast6"
        ]) );
        set("pre_exit_func",([                                                  
	    "east" : "do_east",
	   "west"  : "do_west",
	   "south" : "do_south"
	]) );
	reset();
}
int do_east()
{
     object player;
     player=this_player();
     if ( player->query_temp("east_times")<2+random(6) ) {
         player->add_temp("east_times",1);
         player->move_player(SAREA"coast4","SNEAK");
         return 1;     
     }    
     player->set_temp("can_south",1);
     player->delete_temp("east_times");
     return 0;
}
int do_west()
{
    this_player()->delete_temp("east_times");
    this_player()->delete_temp("can_south");
    return 0;
}
int do_south()
{
    object player;
    player=this_player();
    if ( !player->query_temp("can_south") ) {
        player->move_player(SAREA"coast4","SNEAK");
        player->delete_temp("east_times");
        return 1;
    }
    player->delete_temp("can_south");
    player->delete_temp("east_times");
    return 0;
}