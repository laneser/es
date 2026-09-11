
#include "zeus.h"

inherit ROOM;
inherit DOORS;
void create()
{
  ::create();
  set_short("段家礦坑通道");
  set_long(@CLong
這是一條長長的通道，偶而可以聽到人們的吆喝聲，從聲音中可以聽出充滿
了興奮與快樂的味道，一陣陣的酒香隱隱傳來，北邊是一道鋼鑄的鐵門．
CLong
); 

set("exits",([
             "north":ZROOM"/wineroom03",
             "south":ZROOM"/wineroom01"
             ]));
create_door("north","south",([
            "keyword": ({"gate"}),
            
            "name"   : "iron gate",
            "c_desc" : "一座厚重的鐵門",
            "c_name" : "鐵門",
            "status" : "locked",
            "lock"   : "WINEROOM_DOOR",
            ]));
            
            set("objects",([
                "guard#1":ZMOB"/wine_guard1",
                "guard#2":ZMOB"/wine_guard",
                ]));
reset();
}