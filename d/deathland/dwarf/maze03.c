
#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());
  set_short("the dwarf maze","迷宮");
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
                "west": Deathland"/dwarf/maze02",
                "east": Deathland"/dwarf/darkroom",
                "north":Deathland"/dwarf/darkroom",                 
                "south":Deathland"/dwarf/darkroom", 
             ]));

set("pre_exit_func",([
                      "west": "leave_maze",
                      "east": "maze_3e",
                      "north":"maze_3n",
                      "south":"maze_3s",
                     ]) ); 
::reset();
}

int leave_maze()
{
    return 0;
}

int maze_3e()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m3",1);
      write("你通過魔法障壁到達一個新的地方\n");
      say( this_player()->query("short")+"往東通過魔法障壁\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("short")+"從西邊走了過來.\n");
      }
    return 1;
}

int maze_3n()
{
    mapping x;
    x=this_player()->query_temp("dwarf_echomaze");
    
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      {
       if ( x["m1"]==1 && x["m2"]==3 && x["m3"]==3 && x["m4"]==2 )
         {
         this_player()->move_player(Deathland"/village/v01",({
           "??\n","%s往北通過魔法障壁\n",
           "??\n","%s從南邊走了過來.\n" 
           }),"");
         return 1;
         } 
       else
           return 0; 
      }
    else {
      this_player()->set_temp("dwarf_echomaze/m3",2);
      write("你通過魔法障壁到達一個新的地方\n");
      say( this_player()->query("short")+"往北通過魔法障壁\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("short")+"從南邊走了過來.\n");
      }
    return 1;
}

int maze_3s()
{
    if ( (int)(this_player()->query_temp("dwarf_echomaze/check"))==1 )
      return 0; 
    else {
      this_player()->set_temp("dwarf_echomaze/m3",3);
      write("你通過魔法障壁到達一個新的地方\n");
      say( this_player()->query("short")+"往南通過魔法障壁\n");
      this_player()->move_player(Deathland"/dwarf/maze04","SNEAK","");
      say( this_player()->query("short")+"從北邊走了過來.\n");
      }
    return 1; 
}
