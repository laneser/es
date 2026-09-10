
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
 set_short("the dwarf village","矮人村");
  set_long(@Long
Long
,@CLong
這裡已經是矮人村了.但是卻是一片空曠,似乎沒有人居住的樣子.只見到
一口井(well)與及幾個打水用的木桶,除此之外你還看到一個很大的洞穴在東
邊,一些細微的聲音從洞中傳出,似乎有人住在裡面的樣子.
CLong
);
set("exits",([
                "west":Deathland"/dwarf/village_06",
                "east":Deathland"/dwarf/village_08",
             ]));
set("c_item_desc",([
    "well":"@@to_look_well",
    ]) );

}

string to_look_well()
{
     write("當你看著這口井,忽然你的腳滑了一下,你跌進了井裡.\n\n\n\n\n"
          "\n\n\n\n\n"
          );
     say(this_player()->query("c_name")+"在井旁消失了.\n");
     this_player()->move_player(Deathland"/dwarf/well01","SNEAK","");
     return "一個很深的井,當你環顧四周時,似乎沒有發現出口\n";
}
