#include <mumar.h>
inherit ROOM;
inherit DOORS;
 
void create()
{
        ::create();
  set_short("庫房");
  set_long( @CLong
這裡是牧馬關的武器倉庫，牆上整齊地排列著各式各樣的武器裝備，從刀劍斧矛
到弓弩火炮，樣樣俱全，多得讓你眼花撩亂。聽說這兒還收藏著一些御賜的神兵利器
與來往行商所奉獻的珍奇寶物。
CLong
);
set("light",1);
set("exits",([
               "east":MUMAR"vault01",
             ]));
set("objects",([
               "advisor":MOB"advisor",
               ]) );
 
create_door( "east","west",
           (["keyword" : ({"copper","door"}),
             "name"    : "copper door",
             "c_name"  : "銅門",
             "c_desc"  : "一扇銅門。\n",
             "status"  : "closed"
           ]) );
reset();
}
