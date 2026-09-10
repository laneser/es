#include "../echobomber.h"

inherit ROOM;

int letter;
void create()
{
	::create();
  seteuid(getuid());
  set_short("well","廢棄的監獄");
  set_long(@Long
Long
,@CLong
一處非常破舊的地方,充滿了蜘蛛網和灰塵,而在牆角邊有一具巨大的骨骸(skeleton)
躺在那裡.....這另一邊的牆角有一個階梯(stair),似乎可以離開這裡.
CLong
);

set("c_item_desc",([
    "stair":"一個階梯,通向下層的房間.\n",
    "skeleton":"@@to_look_skeleton",
           ]) );
set("search_desc",([
     "skeleton":"@@to_search_skeleton",     
          ]) );

set("exits",([
     "down":Deathland"/dwarf/prison",
     ]) );
 ::reset();
}

void reset()
{
   ::reset();
   letter=0;
}

string to_look_skeleton()
{
   switch(letter) {
   case 0:
   return "一個巨大的骨骸,由大小來判斷應該是巨人的骨骸,在他的手上\n"
          "似乎握著一個東西\n";
   case 1:
   return "一個巨大的骨骸,由大小來判斷應該是巨人的骨骸\n";
   }
}

string to_search_skeleton()
{
   object ob1;
   switch(letter) {
   case 0:  
     letter=1;
     ob1=new(Object"/letter01");
     ob1->move(this_player());
     this_player()->set_explore( "deathland#4" );
     return "你從骨骸的手中發現了一張破舊發黃的破紙\n";
   case 1:
     return "在一陣仔細的搜索下,你只能確定這是個巨人的骨骸\n"; 
   }  
}
