
#include "../echobomber.h"

inherit ROOM;

int be_digged;
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
    "chest":"@@to_look_chest", 
     ]));
set("search_desc",([
    "riprap":"@@to_search_riprap",
    "here":"@@to_search_here",
    "chest":"@@to_look_chest",
    ]) );
set("direction","block");
set("exits",([
             "northeast":Mine"/m21",             ]));
reset();
}
string to_search_here()
{
     return "當你搜索這地方的時候,你的目光的焦點放在那堆堵住路的亂石(riprap)上\n";
}

string to_search_riprap()
{
    if (be_digged==0)
        return "一堆雜亂無章的石頭,但是似乎在它的後面隱藏著一個秘密\n";
    else 
      return "一堆雜亂無章的石頭.但是似乎有人曾挖掘過它\n"; 
}

int to_find_excavate(string str)
{
    object ob1;
    if ( str!="riprap" ) {
      tell_object(this_player(),"你想挖掘甚麼?\n" ); 
      return 1;
      }
    if ( be_digged!=0 ) { 
      tell_object(this_player(),"你挖了再挖,還是沒有發現任何東西.\n"); 
      return 1;
      }
    else {
      tell_object(this_player(),
        // "you find a mystic chest in the underground,but seems no key to unlock it!\n " 
         "你發現了一個神秘的寶箱(chest),但是似乎被上鎖了\n" 
          );
      be_digged++;   
      return 1;
      }
}
string to_look_chest()
{
    if ( be_digged==0 )
      return 0;
    else 
      return "一個很神秘的寶箱\n";
}
void reset()
{
  ::reset();
  be_digged=0;
}

