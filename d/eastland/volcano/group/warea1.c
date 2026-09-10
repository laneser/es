#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮靈族部落入口");
	set_long( 
@LONG_DESCRIPTION
這裡是矮靈族部落群的入口，整個部落的外圍除了挖了深深的壕溝之外，還用一根根
的木樁把整個部落圍起來，防的不是猛獸而是火山偶而爆發所流出的岩漿，進出部落
必需經過一座可控制的吊橋，不過在平常這座吊橋都是放下來的，有兩名守衛站在門
口保護部落並觀察火山的狀況。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "out" : ONEW"wild16",
     "east" : OGROUP"warea3" ]) );
set( "objects", ([
     "wguard#1":OMONSTER"wguard",
     "wguard#2":OMONSTER"wguard",
     ]) );
set( "pre_exit_func", ([
     "east" : "to_east",
     "out":"to_leave" ]) );
set_outside("eastland");
reset();
}

int to_leave()
{
  write("你離開部落，向外走去。\n");
  return 0;
}

int to_east()
{
  if (!present("soldier"))
    return 0;

  if (present("head",this_player()))
  {  write("守衛看一看你帶的人頭，說道：嗯、你是我們的兄弟，進去吧!\n");
     this_player()->set_explore("eastland#37");
     return 0;
  }

  write("守衛說：你沒有獵人頭來，很抱歉不能讓你通過。\n");
  write("        找一個倒黴鬼，割下他的頭吧 ! \n");
  return 1;
}
