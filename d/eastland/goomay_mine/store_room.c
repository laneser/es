

#include <zeus.h>

inherit ROOM;
int magic_metal;
void create()
{
  ::create();
  set_short("儲藏室");
  set_long(@CLong
你來到一個堆滿原始礦石的儲藏室，有些礦石看起來毫不起眼，但是卻是
製造武器的絕佳材料，也許你可以在此地找到傳說中的魔法磁鐵礦．
CLong
);
   

set("exits",([
             "north":ZROOM"/mine13"
             ]));
set("objects",([
             "iron troll":ZMOB"/iron_troll" ]) );
reset();
}

void init()
 {
    add_action("do_search","search");
 }    
void reset()
 {
   ::reset();
   magic_metal=1;
 }  
 int do_search()
 {
        object obj;   
      if(present("troll")) {
      write("你看見巨人以很不友善的眼光注視著你．．．你急急忙忙地\n");
      write("翻動礦石尋找著，卻一無所獲．\n");
      tell_room(this_object(),(
      this_player()->query("c_name")+"很急忙地搜索了一遍，露出了失望的表情！\n"),
               this_player() );
               return 1;
      }
     if (magic_metal){
       write("你仔細尋找一遍，終於在牆角找到一塊黑黑的石頭．\n");
       tell_room(this_object(),(
           this_player()->query("c_name")+"突然露出驚喜的表情!\n"),
           this_player() );       
       obj=new(ZOBJ"/magic_metal.c");
       obj->move(this_object());
       magic_metal =0;
       return 1;
                     }
     else
     {
       write("你上上下下找了好久，就是沒有發現任何東西！\n");
       return 1;
     }
 }
