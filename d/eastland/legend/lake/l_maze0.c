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
光反射其身上，好似一顆顆亮晶晶的銀寶石。前面不遠處就是海堤了，如果你累了
可以從這上堤岸休息(rest)。
LONG
    );
    ::reset();
}

void init()
{
  ::init();
  add_action("take_a_rest","rest");
}

int take_a_rest()
{
  object obj;
  if ( obj=present("oar",this_player())) obj->remove(); 
  this_player()->move_player(LAKE"village14","SNEAK");  
  tell_object(this_player(),
            "老船東笑著對你說 :這麼快就回來啦。然後一把把你拉上岸來。\n");
  tell_room(environment(this_player()),sprintf(
          "你看到%s下船走了過來。\n",this_player()->query("c_name")),
          this_player());
  return 1;
}