#include "../oldcat.h"

inherit ROOM;

int showed;
void create()
{
	::create();
    set_short( "神殿走廊");
	set_long( 
@LONG
一條長長的走廊，一面壁畫畫出一位穿戴甲冑的矮靈族勇士騎著一不知名的野
獸，右手高舉著長矛刺倒向他撲擊的獨角獸(unicorn)，往東可以通到右殿，往南可
通到正殿，往北可通向後院。
LONG
	);
set( "exits", ([
     "east" : OTEMP"temple20",
     "north" : OTEMP"temple12",
     "southwest" : OTEMP"temple6"
     ]) );
set( "item_desc", ([
     "unicorn":"@@look_unicorn",
     ]) );
reset();
}

string look_unicorn()
{
  object ob;

  if (present("unicorn",this_object()) || showed)
    return "一隻正在和武士戰鬥的獨角獸。\n";
  write("你看著這唯妙唯肖的獨角獸............\n");
  write("看著看著，你發覺你和它的距離越來越近.........\n");
  write("你覺的不對勁，忙把眼睛閉起來.....再張開時，嚇 ! 獨角獸竟然在你面前。\n");
  ob=new(OMONSTER"unicorn");
  ob->move(this_object());
  showed=1;
  return "\n"; 
}

void reset()
{
  ::reset();
  showed=0;
}
