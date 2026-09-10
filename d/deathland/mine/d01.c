
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big hole of Drawf mine ","矮人礦坑的大洞");
  set_long(@Long
Long
,@CLong
一個很黑很暗的大洞穴,曾經是個含量豐富的礦坑,但是自從傳出這裡出現怪物後
就沒有什麼人敢來了.
CLong
);
set("direction","machine");
set("exits",([
             "up":Mine"/m63",
             "west":Mine"/d02",
             ]));
set("pre_exit_func",([
    "west":"to_west",
    ]) );
set("no_monster",1);
reset();
}

int to_west()
{
    write("當你往西走的時候,似乎一道隱形的力量橫越在巖壁上.\n");
    return 0;
}
