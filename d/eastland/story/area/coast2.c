#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("沙灘");
	set_long( @LONG
你現在來到了一處平坦的白沙灘，西邊是一望無際的大海，有大海上有幾塊禿
出海面的礁石，頭頂是炙熱的豔陽和一抹無垠的青空。波浪慢條斯理地拍打著沙岸
，濺起些許水花；海風徐徐輕拂著你的臉頰，吹散了周遭炙窒的熱氣，四肢百駭彷
佛感受到它的恩惠，掃盡了酷署的日照；沙灘上各式貝類星羅棋佈或遊走著小螃蟹
；海里頭穿梭著五彩斑斕的魚兒。徜徉在這一片白沙灘裡，頓時感到煩惱盡失，使
你不再想到任何殺伐爭執。
LONG
	);
        set("light",1);
	set("exits", ([ 
       	    "east" : SAREA"coast3", 
           "north" : SAREA"coast1",
           "south" : SAREA"coast1",
        ]) );
	set("objects", ([
	  "crab#1" : SMOB"crab1",
          "crab#2" : SMOB"crab2",
          "crab#3" : SMOB"crab3",
          "crab#4" : SMOB"crab4",
	]) );
        set( "c_item_desc" ,([
          "礁石" : "幾塊禿出海平面的岩石，你可以沿海岸遊 ( swim ) 過去。\n"        
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
   add_action("do_swim","swim");
}
int do_search( string arg )
{
   write("你發現海面上有幾塊禿出的礁石，如果你遊技好可以游過去( swim )！\n");
   return 1;   
}
int do_swim( string arg )
{
   object player;
   string c_name;
   player=this_player();  
   c_name=player -> query("c_name");
   tell_object(player,
      "你沿著海岸往不遠處的礁石游過去．．\n");
   tell_room(this_object(),sprintf(
      "%s沿著海岸往不遠處的礁石游過去．．\n",c_name),player);
   player->move_player(SAREA"stone1","SNEAK");
   return 1;
}