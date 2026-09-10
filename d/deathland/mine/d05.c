
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big cave of Drawf mine ","矮人礦坑的大洞穴");
  set_long(@Long
Long
,@CLong
一個很黑很暗的大洞穴,曾經是個含量豐富的礦坑.在這裡的地上充滿了黑色的
泡沫和一些骨骸. 在地上有一個水池(pool),裡面傳來一些優美的聲音,似乎想吸引
你進去的樣子.
CLong
);
set("c_item_desc",([
    "pool":"一個小小的水池,但似乎有生物居住的樣子.\n",
//    "skeleton":" ",
//    "bubble":" ",
    ]) );
set("exits",([
             "east":Mine"/d04",
             ]));
reset();
}
void init()
{
   add_action("to_enter","enter");  

}

int to_enter(string str)
{
   if (!str || str!="pool") write("Enter what.\n"); 
   else {
     write("你進入了水池.\n");
     this_player()->move_player(Mine"/d06",({"%s enter the pool.\n","%s進入了水池",
       "%s enters from outside.\n","%s 從外面進來這裡.\n"}),"");
     } 
   return 1;
}
