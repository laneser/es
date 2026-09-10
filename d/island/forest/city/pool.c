#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("香津美泉");
    set_long(@LONG
這裡有個聚集清淨泉水的小水池，泉水自假山上湧出，形成一道小瀑布
流下，下頭有個小鬥勺，當水注滿時，鬥勺就會傾倒使水流入池中；水池中
一群鯉魚悠閒的遊著；迎著一陣陣的清風，傾聽著鬥勺一聲聲的敲著石頭，
未嘗不是一種情趣！
LONG
      );
      set("light",1);
      set("water_source",1);
      set_outside("island");
      set("exits",([
          "north":CITY"inway1"]) );
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
   
   tell_object( this_player(),"你蹲下來喝了幾口甜美的泉水...........\n");
   tell_room(environment(this_player()),
    this_player()->query("c_name")+"緩緩的蹲了下來，仔細的品□著池中的泉水！\n"
   ,this_player() );
   
   if( (string)this_player()->query("class") != "knight") 
       return notify_fail("你心想：唉，這水不過如此而已嘛！\n");
   tell_object(this_player(),"喝了泉水後，你的精神似乎好多了！\n");
   tell_room( environment(this_player() ),
      "突然間他舉起雙手，大叫一聲～喵喵萬歲～，你心想，這泉水有問題哦！\n"
      ,this_player() );
   this_player()->set("spell_points",(int)this_player()->query("max_sp") );
   return 1;
}  