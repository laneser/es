// /u/e/echobomber/deathland/fog1.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
        set_short("Fog","一片黑茫茫的霧");
set_long(@Long
Long
,@Clong
你已經進入了一片黑茫茫的霧裡了. 四面八方都是一片黑色的霧海, 除了這裡以外,
你完完全全地無法看見四周的環境, 若是你隨意亂走的話, 說不定會掉入無底的深淵之
中. 當你每次邁開你的腳步離開這裡去探險別的地方時, 你所須做的不僅是小心而已,
你還須要大量的運氣.
Clong
	);
#include <../replace_room.h>
}
