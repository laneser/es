
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" Drawf mine ","矮人礦坑");
  set_long(@Long
Long
,@CLong
這裡是礦坑的深處.你能看到的是一個周圍的巖壁充滿著被挖掘的痕跡以及
用木頭架設著以免塌陷的巖洞.在地上有鐵軌鋪設著.專供運礦車通行使用.然而
這裡是鐵軌的盡頭,前面的路似乎被一堆塌陷的石塊與木頭擋住了去路.
CLong
);
set("c_item_desc",([
    "riprap":"@@to_search_riprap",
     ]));
set("search_desc",([
    "riprap":"@@to_search_riprap",
    "here":"@@to_search_here",
    ]) );
set("direction","block");
set("exits",([
             "north":Mine"/m47",
             ]));
reset();
}
string to_search_here()
{
     return "當你搜索這地方的時候,你的目光的焦點放在那堆堵住路的亂石(riprap)上\n";
}

string to_search_riprap()
{
    return "一堆雜亂無章的石頭,但是似乎在它的後面隱藏著一個秘密\n";
}

int to_find_excavate(string str)
{
    object ob1;
    if ( str!="riprap" ) {
      tell_object(this_player(),"你想挖掘甚麼?\n" ); 
      return 1;
      }
    tell_object(this_player(),
             "這些石頭在你的努力之下,終於有些鬆動了,但是你不能挖通這裡,\n"
             "雖然一些聲音斷斷續續由石頭的後面傳出,但是你只能呆呆地站在\n"
             "這裡而束手無策,難道這些小石頭能困住你嗎?不行的,只是你沒有\n"
             "使力點,如果能有一股大的力量來衝擊它,\或許你可以發現隱藏於\n"
             "後的秘密.\n");
    this_player()->set_explore("deathland#7");
    return 1;
}
