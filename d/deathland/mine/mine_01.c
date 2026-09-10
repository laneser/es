
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("direction","south");
  set_short("The Entrance of Drawf mine","矮人礦坑的入口");
  set_long(@Long
Long
,@CLong
自古至今矮人對於金子就有一種特殊的能力,他們傯是能夠發掘任何藏在地
底深處的任一處金礦,所以金子對於矮人似乎沒有多大的吸引力. 但是另一種礦
產,Mithril 礦,製造武器與防具不可或缺的金屬,對於正處於戰爭狀態的矮人們
來說,它就顯得特別的重要了.這裡是矮人礦坑的入口.這個礦坑提供矮人不可或
缺的金屬 Mithril 和許多人夢寐以求的黃金.
在地上有鐵軌鋪設著.專供運礦車通行使用.你能看到許多運礦車來來往往.矮人
正辛勤地工作著.鐵軌一直延伸到地底深處,通往未知的世界,而鐵軌的另一端是
到東邊的一座煉礦廠.
CLong
);
set("exits",([
//             "east":Deathland"/mine/factory",
             "north":Deathland"/city/c6",
             "south":Deathland"/mine/mine_02"
             ]));
#include <replace_room.h>
}
