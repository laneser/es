
#include "zeus.h"

inherit ROOM;
inherit DOORS;
void create()
{
  ::create();
  set_short("酒境");
  set_long(@CLong
這是一間充滿酒味的房間，由於密閉式的設計，這裡沒有留下任何的通風孔
所以除了門之外，四周都是光禿禿的巖壁，地上擺置著許許多多的酒罈子，大小
不同形狀也千奇百怪，真不知道到底這裡藏了多少種的酒．南邊是一道鋼鑄的鐵
門．
CLong
); 

set("exits",([
             "south":ZROOM"/wineroom02"
             ]));
create_door("south","north",([
            "keyword":({"gate"}),
            
            "name"   :"iron gate",
            "c_desc" :"一道厚重的鐵門",
            "c_name" :"鐵門",
            "status" :"locked",
            "lock"   :"WINEROOM_DOOR",
            ]));
  set("objects",([
                 "drunk" : ZMOB"/mine_drunk",
                 "wine#1" : ZOBJ"/da_chu",
                 "wine#2" : ZOBJ"/da_chu"
                 ]));
reset();

}
void init()
{
  if(this_player()) this_player()->set_explore("eastland#15");
}
