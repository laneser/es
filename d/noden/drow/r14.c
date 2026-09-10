#include "iigima.h"
inherit ROOM;

void create()
{
        ::create();
        set_short( "pool","小水池");
        set_long(
@C_LONG
這是一個清淨的小水池，黑暗精靈村沒有水井，所有的飲用水，
都是由這口小水池所供應，因為這裡是自然湧出的礦泉，而又不受到
外來生物的干擾，看到清澈的泉水，令你不禁口渴了起來！
C_LONG
        );

        set( "light",0 );
        set( "water_source",1 );
        set( "exits", ([
                     "east":  DROW"r15",
        ]) );
        set("objects", ([
                "child#1": DRO"child",
                "child#2": DRO"child",
        ]) );
        set("c_item_desc",(["pool":
@C_LONG
這個甘泉是黑暗精靈村的唯一水井，你看了看，好像很深的樣子。
C_LONG
           ]));         
        reset();
}
void init()
{
   add_action("do_drink","drink");
}

int do_drink(string str)
{
   if( !str || str!="water")
      return notify_fail("你想喝什麼？\n");

   tell_object( this_player(),"你迫不及待的趕快喝幾口甜美的泉水....\n");
   tell_room(environment(this_player()),
    
this_player()->query("c_name")+"像條小狗似的趴下去喝水！\n"
   ,this_player() );

   if( (string)this_player()->query("class") != "knight")
       return notify_fail("你喝了幾口，感覺口角有種黴味！呃～\n");
   tell_object(this_player(),"喝了泉水後，你的精神似乎震奮了不少！\n");
   tell_room( environment(this_player() ),
      "他喝完水，拍拍身上的灰塵，站了起來！\n"
      ,this_player() );
   return 1;
}
