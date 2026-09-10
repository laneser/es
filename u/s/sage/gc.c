//公會門口的廣場
#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
      set_short( "boss的婆家" )
        set_long(
       "這是聖人的睡房，比外面乾淨多了，屋子中間放著的不用說了是床，沒有什麼特別的,\n"
  "特別的是床頭掛著一張照片，一個年輕美貌的少女的照片，你不禁看呆了\n"
  "真想走過去吻她。。。。。。。。。。在照片的右下角寫著:\n"
 "                           my wife:qwe\n"
        );
     set( "light",1 );
     set( "exits", ([
          "north" : "/u/s/sage/home/work.c",
        ]) );
