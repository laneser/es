#include "oldcat.h"

inherit ROOM;
inherit DOORS;
void create()
{
        ::create();
        set_short("看守室" );
        set_long(
@LONG
這是一間陰森森的矮靈族的看守室，是個看守他們抓來祭品的地方，你似乎聽到從
東邊傳出求救的聲音。
LONG
        );
	set( "exits", ([
        "out" : ONEW"varea6",
        "east" : ONEW"wcave2"
	]) );
        set( "pre_exit_func",([
             "east":"to_east"
              ]) );
        set( "objects",([
               "wjailor" : OMONSTER"wjailor"
             ]) );
        create_door( "east","west", ([
                     "keyword" : ({"door","thick door"}),
                     "name" : "thick door",
                     "c_name" : "厚厚的門",
                     "status" : "locked",
                     "lock" : "WGUARD",
                     "desc" : "You see a door.\n",
                     "c_desc" : "一扇厚厚的木門上面有個鑰孔。\n"
                    ]) );
        reset();
}

int to_east()
{
  if(!present("guard")) {
      return 0;
  }
  else {
      write("守衛說道：想劫獄，等通過我這一關在說吧。\n");
      return 1;
  }
}
