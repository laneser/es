
// Deathland/ruin1/house01.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	 ::create();
     set_short("the council","議會");
     set_long(@Long
Long
,@CLong
這裡是遺蹟的議會 .一處很大的建築, 四周圍著著一排排的座位, 而中間是主席臺
與外面的景像比較起來, 這個地方似乎是一個安詳的地方, 似乎沒有任何肅殺的氣氛. 
CLong
);
     set("search_desc",([
         "here":"@@search_here",
         ]) );
     set("exits",([
         "out":Deathland"/ruin1/ruin11",
         ]) );
     set("crystal",1);
     reset();
}

string search_here()
{
    object item;
    if ( query("crystal") ) {
      item=new(Object"/crystal01");
      item->move(this_object());
      this_player()->set_explore("deathland#19");
      set("crystal",0);
      return "當你仔細搜查這裡的時候, 你發現了一顆紫色的水晶.\n";
      }  
    return "似乎有人先搜查過這裡了.\n";
}

void reset()
{
   ::reset();
   set("crystal",1);
}
