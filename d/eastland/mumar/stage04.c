//#pragma save_binary
#include <mumar.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("軍官寢室");
  set_long( @CLong
你走進了一間軍官寢室。房間裡除了一張小小的桌子外，就是放置在角落的一張
木床了。桌上放了一盞油燈和一本兵法書，床上的白色床單上整齊地放置著像豆乾般
的薄被。你感覺這兒的主人是個一絲不苟的人。從這兒往南可以回到軍官辦公室。
CLong
);
set("light",1);
set("exits",([
               "south":MUMAR"stage03",
             ]));
set("objects",([
               "general":MOB"hen"]) );
reset();
#include <replace_room.h>
}
