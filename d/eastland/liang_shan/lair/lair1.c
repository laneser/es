#include "../takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "狹窄通道" );
	set_long(@C_LONG
你進入了山洞中的狹窄通道，潮溼而且陰暗，空氣中瀰漫著一股說不出來
的噁心氣味，你仔細的分析它，有黴味，動物排洩物的氣味，甚至還有屍體腐
敗的味道，前面角落似乎有什麼東西蠢蠢欲動，無邊無際的恐懼緩緩自你心中
升起，你的第六感命令你趕快離開...
C_LONG	
	);
        set( "exits", ([
                "out" : TROOM"forest1",
                "north" : TROOM"lair/lair2"
        ]) );
        reset();
}
int clean_up() { return 0; }
