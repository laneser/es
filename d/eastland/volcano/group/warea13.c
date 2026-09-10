#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮靈族部落");
	set_long( 
@LONG_DESCRIPTION
這裡是矮靈族部落群，西南邊可通到廣場，這裡的建築物大都是石造的，少數人
住帳蓬，地上用很多石板鋪成的路貫穿整個部落，整個部落給人的感覺是非常寧靜且
安詳的，由於火山已經有很多年沒有爆發了，因此新一代的族人也慢慢的就淡忘了此
事，一棟石造房子(house)矗立在這兒。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "southwest" : OGROUP"warea10",
     ]) );
set( "objects", ([
     "wguard":OMONSTER"wguard",
     ]) );
set("item_desc", ([
    "house": "一棟石造的房子，看起來是呈黑紅色的，還有個火龍的雕飾在房屋的屋頂，不知道\n是誰住在這裡？\n",
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
  if (!arg || arg!="house" ) {
    write("你要進去那裡？\n");
    return 1;
  }
  tell_object(this_player(),"你走進這間房子裡\n");
  tell_room(this_object(),"你見到"+this_player()->query("c_name")+"走進房子裡。\n",this_player());
  this_player()->move_player(OGROUP"house4","SNEAK");
  return 1;
}
