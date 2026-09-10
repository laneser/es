#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮靈族部落");
	set_long(
@LONG_DESCRIPTION
這裡是矮靈族部落群，西邊可以通到出口，東邊可通到廣場，這裡的建築物大都是石
造的，少數人住帳蓬，地上用很多石板鋪成的路貫穿整個部落，整個部落給人的感覺
是非常寧靜且安詳的，由於火山已經有很多年沒有爆發了，因此新一代的族人也慢慢
的就淡忘了此事。一座構築宏偉的神殿(temple)矗立在這兒。
LONG_DESCRIPTION
	);
set("item_desc", ([
    "temple" : "一座巨大的矮靈族神殿，這座神殿供奉著他們最崇拜的神，火神。\n",
    ]) );
set( "exits", ([ 
     "west" : OGROUP"warea11" ]) );
set_outside("eastland");
reset();
}

void init()
{
   add_action("do_enter","enter");
}

int do_enter(string arg)
{
  if (!arg || arg!="temple" ) {
    write("你要進去那裡？\n");
    return 1;
  }
  tell_object(this_player(),"你走進這座神殿中。\n");
  tell_room(this_object(),"你見到"+this_player()->query("c_name")+"走進神殿內。\n",this_player());
  this_player()->move_player(OTEMP"temple1","SNEAK");
  return 1;
}
