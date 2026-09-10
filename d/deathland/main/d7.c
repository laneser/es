
#include "../echobomber.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set("light",1);
       set("short","一個很深的洞穴");

       set("long",@Clong
當你來到這個地方時,你發現東邊的巖壁上有一個石門(stone door),而且
門上有一個板子(board),西邊則是一個很大的洞穴,北方是一個斜坡,通往未知
的深處,而南邊是一個往上的洞穴.風從地底不停地吹上來,你覺得越來越冷了.
Clong
          );
set ("item_desc",([
"board":@Board
 ---------------------------------------------------------------------
       這是通往矮人國度的入口,假如你願意幫助我們對抗邪惡的山頂巨人的
       話,歡迎你,我的朋友.
                         --皇家侍衛隊長 卡爾服德(Calford)
---------------------------------------------------------------------
Board
 ]));
 set("exits",(["southup":Deathland"/main/d3",
               "west":Deathland"/troll/cave_01",
               "east":Deathland"/city/c1",
               "northdown":Deathland"/main/d8",
              ]) );
create_door("east","west",([
             "keyword" : ({"stone door","door" }),
             "status" : "closed",
             "c_desc" : "一扇結實厚重的石門",
             "c_name" : "石門",
             "name":"stone door",
             "desc":"a stone door"
              ]) );
reset();
}
