#include "goomay.h"

inherit ROOM;

int mark;
void create()
{
        ::create();
        set_short("奇異的房間");
        set_long( @LONG_DESCRIPTION
你現在正位於一個奇異的房間中，這裡跟其他地方有顯著的不同，
一點也不顯得髒亂和燥熱，傢俱和擺設都十分恰當，靠牆的地方還有
一個小小的櫥櫃(closet)和鏡臺，一股股的涼風不知道從哪裡吹來，
令人十分舒暢。
LONG_DESCRIPTION
        );

set("item_desc",([
    "closet":  "這是一個美麗的雕花櫥櫃，看起來只是個衣櫃。\n" 
           ]) );
set("search_desc",([
     "closet":"@@to_search_closet",     
          ]) );

set("exits",([
     "east"	:  Goomay"cellar5",
     ]) );

 reset();
}

void init()
{
        if (this_player()) this_player()->set_explore("eastland#11");
}
void reset()
{
   ::reset();
   mark=0;
}

string to_search_closet()
{
   object ob1;
   switch(mark) {
   case 0:  
     mark=1;
     ob1=new(Obj"ingot");
     ob1->move(this_player());
     return "你仔細的翻箱倒櫃，最後只發現了一面奇怪的破金牌。\n";
   case 1:
     return "在一陣仔細的搜索下，再也找不到有趣的東西了。\n"; 
   }  
}
