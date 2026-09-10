
// Deathland/ruin1/down03.c

#include "../echobomber.h"

inherit DOORS;
inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遺蹟地下儲藏室");
     set_long(@Long
Long
,@CLong
這裡是遺蹟的地下儲藏室 ,似乎是用來放置飲水與食物的地方 .這裡的地上與前
面的地方不同 ,十分乾淨 .\或許這地方是儲藏室吧 .但是這個地方卻有一種令人毛骨
悚然的感覺 .
CLong
);
     set("objects",([
         "wight":Monster"/wight02",
         ]) );
     
     set("exits",([
         "north":Deathland"/ruin1/down02",
         ]) );
     create_door("north","south",([
             "name":"stone door",
             "c_name":"石門",
             "keyword":({"stone door","door",}),
             "c_desc":"石門",
             "status":"closed",
             "desc":"a stone door",
                     ]) );    
     ::reset();
}

void init()
{
    this_player()->set_explore("deathland#18");
}
