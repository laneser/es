
// Deathland/ruin1/down02.c

#include "../echobomber.h"

inherit DOORS;
inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遺蹟地下室");
     set_long(@Long
Long
,@CLong
這裡是遺蹟的地下室 ,似乎是用來避難的地方 .然而地上到處是一堆堆的骨骸與乾
掉的血跡 .更讓人覺得氣氛顯得十分的詭異 .你無法想像當時的情況是如何 ,但是你或\
\許可以理解到為甚麼這地方一直沒有人發現它 ,因為當時的一場災難把這座城市的人都
給毀滅了 .甚至於躲在這裡的人都不能幸勉 .南邊有一個石門 ,在門後似乎是儲藏食物
與飲水的地方 ,但是你不能確定目前裡面會有什麼東西 .
CLong
);
     set("exits",([
         "south":Deathland"/ruin1/down03",
         "north":Deathland"/ruin1/down01",
         ]) );
     create_door("south","north",([
             "name":"stone door",
             "c_name":"石門",
             "keyword":({"stone door","door",}),
             "c_desc":"石門",
             "status":"closed",
             "desc":"a stone door",
                     ]) );    
     ::reset();
}

