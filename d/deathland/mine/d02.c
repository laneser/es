
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big cave of Drawf mine ","矮人礦坑的大洞穴");
  set_long(@Long
Long
,@CLong
一個很黑很暗的大洞穴,曾經是個含量豐富的礦坑,但是自從傳出這裡出現怪物後
就沒有什麼人敢來了.越往西走,就覺得似乎有人在窺探你的樣子.
CLong
);
set("exits",([
             "west":Mine"/d03",
             "east":Mine"/d01",
             ]));
set("pre_exit_func",([
    "east":"to_east",
    ]) );
reset();
}

int to_east()
{
    write("當你往東走的時候,似乎一道隱形的力量橫越在巖壁上.\n");
    return 0;
}
