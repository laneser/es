
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("well","廢棄的監獄");
  set_long(@Long
Long
,@CLong
一處非常破舊的地方,充滿了蜘蛛網和灰塵,而在牆角邊有一具巨大的骨骸(skeleton)
和一副鐵銬.似乎這裡應該是個監獄.這另一邊的牆角有一個階梯(stair),似乎可以通向較
高的地方而離開這裡.
CLong
);

set("c_item_desc",([
    "stair":"一個階梯,通向上層的房間.\n",
    "skeleton":"一個巨大的骨骸,由大小來判斷應該是巨人的骨骸\n",       
    "wall" : "一片黑漆漆的牆壁,上面有著奇怪的文字,似乎是巨人族的文字\n"       
           ]) );
set("search_desc",([
     "skeleton":"@@to_search_skeleton",     
          ]) );

set("exits",([
     "northeast":Deathland"/dwarf/well05",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_climb","climb");
}

int to_climb(string str)
{
    if(!str||str!="stair") return 0;
    else {
      this_player()->move_player(Deathland"/dwarf/prison02","SNEAK","");
      return 1;
      }
}

string to_search_skeleton()
{
   return "你發現這具骨骸的手好像在牆壁上畫些甚麼\n";
}
