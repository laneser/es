#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("神殿重地");
	set_long(
@LONG_DESCRIPTION
你現在位於神殿重地，四壁蕭然，上面一扇天窗打的開開的，假如沒啥事請快點離開。
一位矮靈族的長老正在這裡閉關，他正在想怎麼樣才能讓火山停止爆發。
LONG_DESCRIPTION
	);
set( "exits", ([
     "north": OTEMP"temple25",
     ]) );
set_outside("eastland");
set("objects", ([
    "elder":OMONSTER"elder",
    ]) );
set("have_book",1);
set("wall_box_for_mar_short",1);    
reset();
}

int reset()
{
  set("have_book",1);
  ::reset();
}

void init()
{
  add_action("do_search","search");
}

int do_search(string arg)
{
  object me;
  
  me=this_player();
  
  if (!((me->query_temp("known_book_of_sword"))||(me->query_quest_level("Ohio's_brother"))))
    return 0;
  if (present("wraith elder",environment(me))) {
    tell_object(me,"矮靈族長老生氣地擋在你面前阻止你繼續搜索的行動搜索。\n");
    return 1;
  }
  tell_object(me,
 "你經過一番仔細的尋找，發現在牆壁上像一個像鑰匙孔般特殊的暗洞(wall_hole)。\n");
  me->set_temp("can_insert_key",1); 
  return 1;
}
