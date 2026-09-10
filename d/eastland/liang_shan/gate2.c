#include "takeda.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set_short("鐵柵");
       set_long( @Clong
你來到一條林間小徑，小徑的盡頭是一道厚重的大鐵柵，鐵柵旁立了一個大
告示(board)，上面寫了一些字。一個黝黑的大漢抱著一把斧頭，正躺在告示
下呼呼大睡，發出如雷的鼾聲......Z....Z....Z.....
Clong
          );
set ("c_item_desc",([
"board":@Board
 ---------------------------------------------------------------------
  注意    梁山泊禁地
               
                   妄入者死一百次                        宋江
---------------------------------------------------------------------
Board
 ]));
 set_outside( "eastland" );
 set("exits",([
               "north":TROOM"path9",
               "south":TROOM"path8",
              ]) );
 set("objects",([
               "li":TMONSTER"li"
               ]));
 set( "pre_exit_func", ([
               "north" : "check_flag"
               ]));
create_door("north","south",([
             "keyword" : ({"iron prism","prism" }),
             "status" : "closed",
             "c_desc" : "一道厚重的鐵柵",
             "c_name" : "鐵柵",
             "name":"iron prism",
             "desc":"an iron prism"
              ]) );
reset();
}
int check_flag()
{
      if ( wizardp(this_player()) || !present("li")) return 0;
      if ( present("flag",this_player()) ) return 0;
      else {
      tell_object( this_player(),
         "李逵忽然張開眼睛說道: 沒有令旗不準進去，說完眼睛一閉，又睡著了...\n");
    return 1;
           }       
}
int clean_up() { return 0; } 