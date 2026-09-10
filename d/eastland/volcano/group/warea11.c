#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮靈族部落");
	set_long( 
@LONG_DESCRIPTION
這裡是矮靈族部落群，西北邊可通到廣場，這裡的建築物大都是石造的，少數人
住帳蓬，地上用很多石板鋪成的路貫穿整個部落，整個部落給人的感覺是非常寧靜且
安詳的，由於火山已經有很多年沒有爆發了，因此新一代的族人也慢慢的就淡忘了此
事，你可以看到有一個帳篷(camp)在你的前方。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northwest":OGROUP"warea10",
     "east" : OGROUP"warea16" ]) );
set("objects", ([
    "wboy":OMONSTER"wboy",
    ]) );
set("item_desc", ([
   "camp" : "一個畫滿奇怪符號的帳篷，不知道是誰住在裡面，你想進去瞧瞧嗎?\n",
   ]) );
set_outside("eastland");
reset();
}

void init()
{
   add_action("do_enter","enter");
}

int do_enter(string arg)
{
  if (!arg || arg!="camp" ) {
    write("你要進去那裡？\n");
    return 1;
  }
  tell_object(this_player(),"你走進這帳篷裡\n");
  tell_room(this_object(),"你見到"+this_player()->query("c_name")+"走進帳篷內。\n",this_player());
  this_player()->move_player(OGROUP"house3","SNEAK");
  return 1;
}
