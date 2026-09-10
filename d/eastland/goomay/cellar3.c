#include "goomay.h"

inherit ROOM;

int letter;
void create()
{
	::create();
  set_short("廢棄的地道");
  set_long(@Long
這是一處非常破舊的地方，充滿了蜘蛛網和灰塵，地道中央擺了一張
方桌和幾張躺椅，也許這裡原來是間休息室，而在其中一張椅子上有一具
骨骸(skeleton)躺在那裡。
Long
);

set("item_desc",([
    "skeleton":"@@to_look_skeleton",
           ]) );
set("search_desc",([
     "skeleton":"@@to_search_skeleton",     
          ]) );
set( "objects", ([
	"rat1" : Mob"salamander",
	"rat2" : Mob"salamander", ]) );

set("exits",([
     "north"	:  Goomay"cellar2",
     ]) );

 reset();
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
   return "它是一副高大修長的骨骸，由大小來判斷應該是精靈或半精靈的骨骸，\n"+
		"在他的手上似乎握著一個東西。\n";
   case 1:
   return "一個高大修長的骨骸，由大小來判斷應該是精靈或半精靈的骨骸。\n";
   }
}

string to_search_skeleton()
{
   object ob1;
   switch(letter) {
   case 0:  
     letter=1;
     ob1=new(Obj"letter01");
     ob1->move(this_player());
     return "你從骨骸的手中發現了一張發黃的羊皮紙。\n";
   case 1:
     return "在一陣仔細的搜索下,你只能判定這是個精靈的骨骸。\n"; 
   }  
}
