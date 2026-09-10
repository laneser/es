#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮靈族部落");
    set_long( 
@LONG_DESCRIPTION
這裡是矮靈族部落群，西南邊可以通到出口，南邊可通到廣場，這裡的建築物大都是
石造的，少數人住帳蓬，地上用很多石板鋪成的路貫穿整個部落，整個部落給人的感
覺是非常寧靜且安詳的，由於火山已經有很多年沒有爆發了，因此新一代的族人也慢
慢的就淡忘了此事，你可以看到有一個帳篷(camp)在你的右手邊。
LONG_DESCRIPTION
	);
set( "exits", ([
     "southwest" : OGROUP"warea3",
     "south" : OGROUP"warea9" ]) );
set( "objects", ([
     "wgirl":OMONSTER"wgirl",
     ]) );
set("item_desc", ([
    "camp" : "一個用獸皮縫製而成的帳篷，帳篷上還有一些花花綠綠的裝飾品，從縫製的痕跡\n來看，矮靈族的手工也蠻不錯的，你心裡在猜這□可能是女孩子住的地方。\n",
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
  if (!arg || arg!="camp") {
    write("你要進去那裡？\n");
    return 1;
  }
  tell_object(this_player(),"你走進這帳篷裡\n");
  tell_room(this_object(),"你看到"+this_player()->query("c_name")+"走進帳篷內。\n",this_player());
  this_player()->move_player(OGROUP"house2","SNEAK");
  return 1;
}
