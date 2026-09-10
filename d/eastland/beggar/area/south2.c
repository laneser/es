#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "south2", "『薪膽村』廣場" );
	set_long(@C_LONG
這是一大片黃砂廣場, 因為『丐幫』弟子常在此處練武功, 所以地面顯得光
禿禿的一根雜草也沒有。有時候風颳的很大挾帶著漫天的灰塵, 尤其是每當南邊
的高山吹著『落山風』, 真叫人眼睛睜不開。於是『丐幫』擬定做一些水土保持
的工作, 但是村裡缺乏另一大片空地可以供弟子們練習, 所以每次提出做值地皮
的工作就會遭人反對, 於是乎人們還是得繼續忍受下去。東、西、南和北邊都是
廣場的繼續延申。
C_LONG
	);
	set_outside( "noden" );
	set( "exits", ([
                      "east":DBEGGAR"s2e1.c",
                      "west":DBEGGAR"s2w1.c",
                      "south":DBEGGAR"south3.c",
	              "north":DBEGGAR"south1.c"
	]) );
     reset();
}

