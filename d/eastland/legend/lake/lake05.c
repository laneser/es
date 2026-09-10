#include "../legend.h"

inherit LAKE"in_lake1";

void create()
{
        ::create();
    set_short("大海");
        set_long( 
@LONG
你劃著船槳來到了海面上，極目四眺，是一片風平浪靜的無垠大海，遠處幾艘
漁船正隨著波浪載浮載沈，撒網成群，辛勤地捕著漁。波面上不時穿梭著飛魚，陽
光反射其身上，好似一顆顆亮晶晶的銀寶石。在旁邊不遠處似乎有一座島嶼，你不
禁往水底下一看，似乎劃到了淺灘，或許你可以(get_off)下船看看。
LONG
    );
  ::reset();   
}

void init()
{
 ::init(); 
 add_action("do_get_off","get_off");
}

int do_get_off()
{ 
  if (present("oak oar",this_player()))
    get_object("oar",this_player())->remove(); 
  tell_object(this_player(),
       "你把船槳放下，腳踏處似乎是一處淺灘，你破水而行，來到了一塊沙灘上。\n");
  this_player()->move_player("/d/eastland/story/area/coast1.c","SNEAK");
//  this_player()->move_player("/d/eastland/17,6.east","SNEAK");
  tell_room(environment(this_player()),sprintf(
       "%s從淺灘破水而來。\n",this_player()->query("c_name")),
       this_player());
  return 1;
}
