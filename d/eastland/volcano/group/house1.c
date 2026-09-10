#include "../oldcat.h"

inherit ROOM;
string str1 ="這裡是一個普通年輕人住的帳篷，一根支撐帳篷的柱子上吊著一個獅子的頭，地上\n鋪著一塊鹿皮，你可以想像這裡的主人對狩獵還蠻在行的。\n";
string str2 ="你見到有個年輕人眉頭深鎖，低頭不語，連你進來都不在意，似是為了什麼事在煩惱。\n";

void create()
{
	::create();
set_short("帳棚");
set("long","@@query_look" );
set( "exits", ([
     "out" : OGROUP"warea4"
     ]) );
set( "objects", ([
     "wman" : OMONSTER"wman"
     ]) );
set("light",1);
reset();
}

string query_look()
{
  if (present("the young man"))
    return str1+str2;
  return str1;
}
