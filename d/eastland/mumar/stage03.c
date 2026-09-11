//#pragma save_binary
#include "mumar.h"
inherit ROOM;
 
void create()
{
        ::create();
  set_short("軍官辦公室");
  set_long( @CLong
這兒是一間軍官辦公室。一張五尺見方的檀木桌子就放在辦公室的中央，桌上則
整整齊齊地放著文房四寶，檀香爐裡飄出陣陣檀香，使你感覺彷佛置身仙居。桌子後
面放了兩張紅檜大椅，桌後的牆上則是懸著一個大字－『忍』，旁邊的對聯則是用狂
草所書，你怎麼也看不懂。這裡的南北兩側各有一間軍官寢室，樓下則是育樂中心。
CLong
);
set("light",1);
set("no_monster",1);
set("exits",([
               "north":MUMAR"stage04",
               "south":MUMAR"stage05",
               "down":MUMAR"stage01"
             ]));
#include <replace_room.h>
}
