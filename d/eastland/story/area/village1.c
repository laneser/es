#include "../story.h"
inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("村口");
	set_long(@LONG
你來到了一處羽民族居住的村莊口上，兩旁是一排排的小屋。由於這村落置身
在一大片樹叢裡，顯得格外神秘又隱敝，好似一座天然的住處。另外在道路上種植
了許多葡萄樹，樹上的果實平時供羽民族食物，而果實中的液汁也是羽民族賴以為
生的水源。由於這村落沒什麼活動的空間，小孩子們都會跑到西北邊的草原去遊玩
，但大人們都深以為憂，恐怕這裡被人發現。
LONG
	);
	set("light",1);
	set("exits", ([ 
                "east" : SAREA"house1",
                "west" : SAREA"house2",
               "south" : SAREA"village2",
           "northeast" : SAREA"plain2",
        ]) );
        set("objects" , ([
           "guard#1" : SMOB"guard1",
           "guard#2" : SMOB"guard1",
        ]) );
	reset();
}
