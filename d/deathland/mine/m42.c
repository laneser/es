
#include "../echobomber.h"


inherit ROOM;

int be_digged;
void create()
{
	::create();
  seteuid(getuid());	
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
             "north":Mine"/m31",
             ]));
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
      tell_room(this_object(),
         "一個令人懼怕的眼魔,死亡之眼出現了\n" 
          );
      be_digged++;   
      ob1=new(Monster"/beholder01");
      ob1->move(this_object());
      ob1->kill_ob( this_player() );
      return 1;
      }
}

void reset()
{
  ::reset();
  be_digged=0;
}
