
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Drawf city","矮人國度的墓場");
  set_long(
@CLong
這裡是矮人國度的墓場,埋藏著一些英勇戰死的士兵的骨骸.
CLong
);
set("exits",([
            "north":Deathland"/city/c3",
             ]));
}
