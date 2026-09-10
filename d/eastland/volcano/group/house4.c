#include "../oldcat.h"

inherit ROOM;

string str1 ="你站在酋長所住的房子中，一張巨大的虎皮和獨角獸的角分別掛在房子的左右\n兩面牆上，地上還鋪著一張黑熊皮，房間的角落還擺了一些檀木箱，不知道是放什\n麼東西，一張石椅擺在房屋的正中央。\n";
string str2 ="酋長巴斯格威風懍懍的坐在石椅上。\n";
string str3 ="他的寵物暴狼扒在他的腳旁邊，兩隻眼睛正瞪著你。\n";

void create()
{
	::create();
    set_short("酋長的屋子");
	set("long", "@@query_look" );
set( "exits", ([
     "out" : OGROUP"warea13"
     ]) );
set( "objects", ([
     "wolf" : OMONSTER"wolf",
     "wchief" : OMONSTER"wchief"
     ]) );
set("light",1);
reset();
}

string query_look()
{
  if (present("basge")) {
    if (present("wolf"))
      return str1+str2+str3;
    return str1+str2;
  }
  return str1;
}
