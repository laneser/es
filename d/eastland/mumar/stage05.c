//#pragma save_binary
#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("軍官寢室");
  set_long( @CLong
你走進了一間軍官寢室。房間裡除了一張小小的桌子外，就是放置在角落的一張
木床了。桌上放了一盞油燈和一雙破鞋，紅色床單上的被子則亂七八糟地放置著。牆角
還堆了一些傳來惡臭的衣物。你感覺這兒的主人是個一蹋糊塗的人。從這兒往北可以回
到軍官辦公室。
CLong
);
set("light",1);
set("exits",([
               "north":MUMAR"stage03",
             ]));
set("objects",([
               "general":MOB"ha"]) );
reset();
#include <replace_room.h>
}
