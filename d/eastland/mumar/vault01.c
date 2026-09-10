#include <mumar.h>
inherit ROOM;
inherit DOORS;
 
void create()
{
        ::create();
  set_short("庫房");
  set_long( @CLong
這裡是牧馬關的武器庫的保養中心，地上牆上雜亂地放了許多等待修復的破損武
器和裝備，還有一些簡單克難的打鐵、修補器材。不論要修的東西有多少，這兒的工
匠師父們總是能在最短的時間內完成工作，以供軍需。東邊出去是教場，西邊則還有
一間內室。　
CLong
);
set("light",1);
set("exits",([
               "west":MUMAR"vault00",
               "east":MUMAR"vault02",
             ]));
 
create_door( "west","east",
           (["keyword" : ({"copper","door"}),
             "name"    : "copper door",
             "c_name"  : "銅門",
             "c_desc"  : "一扇銅門。\n",
             "status"  : "closed"
           ]) );
reset();
}
