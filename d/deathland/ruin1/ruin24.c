
// Deathland/ruin1/ruin24.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the ruin","遺蹟");
     set_long(@Long
Long
,@CLong
一座破舊的遺蹟 ,這裡似乎已經荒廢很久了 .地上到處是殘磚破瓦 ,更讓人覺得
這地方已經許久未曾有人煙了 .一種綠色的蘚苔植物附在兩旁的牆壁上 ,使得這地方
的氣氛更顯得十分的詭異 .
CLong
);
     set("exits",([
         "southeast":Deathland"/ruin1/ruin33",
         "northwest":Deathland"/ruin1/ruin15",
         ]) );
     ::reset();
#include <../replace_room.h>
}

