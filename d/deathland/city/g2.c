
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Drawf city","矮人墓場");
  set_long(@Long
這裡是矮人國度的墓場,墓場裡埋藏著一些英勇戰死的士兵的骨骸.每一座墓碑
的底下都有一個英勇的靈魂安息著.
Long
);
set("exits",([
            "north":Deathland"/city/g1",
            "south":Deathland"/city/g3",           
             ]));
}
