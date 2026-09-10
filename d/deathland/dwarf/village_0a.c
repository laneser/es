
#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the secret hole","秘密洞穴");
  set_long(@Long
Long
,@CLong
一個很奇怪的場所.到處都是一些雜亂無章的符號(sign),似乎這裡的主人是個瘋狂的人
CLong
);
set( "c_item_desc",([
     "sign":"一種很奇怪的符號,似乎是一種文字,但是你無法瞭解他.\n"
     ]) );
  
set( "exits",([
             "out":Deathland"/dwarf/village_09",
             "north":Deathland"/dwarf/village_0b",
             ]));

set ( "pre_exit_func",([
      "north":"to_north",
      ]) );
set( "objects",([
     "assassin":Monster"/assassin01",
    ]) );
reset();
}

int to_north()
{
    if (!present("assassin"))
      return 0;
    else 
     write("幻影殺手擋住了你的去路.\n");
     return 1; 
}

