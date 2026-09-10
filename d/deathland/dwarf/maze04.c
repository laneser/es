
#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the dwarf village","迷宮");
  set_long(@Long
Long
,@CLong
一個很大的迷宮(maze)洞穴,東西南北都有通路,但是每個通道上似乎都有魔法
障壁,矮人為了能安安全全地生活著,把自己的村落建築於這個宛如迷宮的大洞之中
,除了矮人自己能夠快速且安全地走到自己的村落外,似乎要到矮人村落是一件困難
的事.
CLong
);
set("exits",([
                "west": Deathland"/dwarf/maze03",
                "east": Deathland"/dwarf/darkroom",
                "north":Deathland"/dwarf/darkroom",                 
                "south":Deathland"/dwarf/darkroom", 
             ]));

set("pre_exit_func",([
                      "west": "leave_maze",
                      "east": "maze_4e",
                      "north":"maze_4n",
                      "south":"maze_4s",
                     ]) ); 
::reset();
}

int leave_maze()
{
    return 0;
}

int maze_4e()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m4",1);
      write("你通過魔法障壁到達一個新的地方\n");
      say( this_player()->query("chort")+"往東通過魔法障壁\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("chort")+"從西邊走了過來.\n");
      this_player()->set_temp("dwarf_echomaze/check",1);
      }
    return 1;
}

int maze_4n()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m4",2);
      write("你通過魔法障壁到達一個新的地方\n");
      say( this_player()->query("chort")+"往北通過魔法障壁\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("chort")+"從南邊走了過來.\n");
      this_player()->set_temp("dwarf_echomaze/check",1);
      }
    return 1;
}

int maze_4s()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m4",3);
      write("你通過魔法障壁到達一個新的地方\n");
      say( this_player()->query("chort")+"往南通過魔法障壁\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("chort")+"從北邊走了過來.\n");
      this_player()->set_temp("dwarf_echomaze/check",1);
      }
    return 1; 
}
