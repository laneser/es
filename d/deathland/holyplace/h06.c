
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A strange place","陰暗的虛無飄渺處");
  set_long(@Long
Long
,@CLong
一處陰暗的地下世界,四處的黑影無聲無息地向你侵襲而來.這裡的寂靜令人感到害怕,
讓你不自主的想要發出一些聲音.沒有風聲,沒有水聲,甚至你無法聽到自己的腳步聲,你不
禁懷疑自己處在一個虛無的地方.幸好你發現你的東方有一道很明亮的光源在那裡.
CLong
);

set("exits",([
             "west":Deathland"/holyplace/h07",
             "east":Deathland"/holyplace/h05",
             ]));
reset();
}
