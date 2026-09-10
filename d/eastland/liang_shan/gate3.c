#include "takeda.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set_short("鐵柵");
       set_long( @Clong
神火炮營的盡頭是一片未開發的林區，無數的參天古木，高聳入雲，濃密的樹蔭
之下，散佈著盤根錯節的枝幹，和各式各樣的底生植物，這使得在這片林中行走
成為非常吃力的一件事。前人為了打獵方便，在林中開闢了一條窄小的便道，但
最近，不知道發生了什麼事，山寨決定將這一片密林封閉起來，於是在此修築了
一道鐵柵，並駐兵防守。
Clong
          );
 set_outside( "eastland" );
 set("exits",([
               "south":TROOM"cannon",
               "north":TROOM"forest1"
              ]) );
 set("objects",([
               "yang":TMONSTER"yang2"
               ]));
 set( "pre_exit_func", ([
               "north" : "check_good"
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
int check_good()
{
      if ( wizardp(this_player()) || !present("yang")) return 0;
      if ( (int)this_player()->query("alignment")>-100 ) return 0;
      else {
      tell_object( this_player(),
         "楊志說道: 吾奉公孫先生之命，把守此處，不許為非作歹之徒進入，看汝之\n"
         "長相，絕非善類，速速離開此地，吾可饒你不死........\n");
    return 1;
           }       
} 
int clean_up() { return 0; }