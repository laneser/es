//#pragma save_binary
#include "mumar.h"
inherit ROOM;
 
void create()
{
        ::create();
  set_short("觀雨樓");
  set_long( @CLong
你走到這兒，看到一座城樓，城樓門旁掛著一個牌子，寫著「觀雨樓」。進了樓
裡，則是一個放置了許多書櫃、棋盤和桌椅的大廳，四周的牆上則都是一些花鳥、山
水畫。角落一個小茶几上放了三套茶具。這兒給你的感覺像是牧馬關官兵的休閒中心
。往上是軍官室，往西可以回到城牆通道上。
CLong
);
set("light",1);
set("exits",([
               "west":MUMAR"wall03",
               "up":MUMAR"stage03"
             ]));
#include <replace_room.h>
}
