#include "../oldcat.h"

inherit ROOM;

string str1= "這是一間矮靈老巫醫所住的帳棚，東邊的架上一大堆瓶瓶罐罐的藥水，藥粉，\n西邊的架上有一大堆有關醫藥的書，房間中還有一個大鍋子，鍋子裡面的液體\n不斷的翻騰著，一陣陣刺鼻的味道，使你幾乎不想再呆在這裡。\n";
string str2="你看到一個老巫醫正用大棍棒攪拌著大鍋裡的液體。\n";

void create()
{
      ::create();
      set_short( "帳棚");
      set("long","@@query_look" );
      set( "exits", ([
         "out" : OGROUP"warea11"
       ]) );
      set( "objects", ([
        "wdoctor" : OMONSTER"wdoctor"
       ]) );
      set("light",1);
      reset();
}

string query_look()
{
  if (present("old shaman"))
    return str1+str2;
  return str1;
}
