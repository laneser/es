
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
  set("light",1);
  set_short("矮人國度的入口");
  set_long(@CLong
往西邊看過去,有一個很大很大的空間,那裡正是矮人國度.在矮人的辛勤的
努力工作下,目前矮人國度已經能夠自給自足了.但是由於山頂巨人的攻擊,矮人
們數代的辛苦經營幾乎毀於一旦.所以矮人為了保衛自己的家園,正在加強 本身
的武力與防護措施.
這是通往矮人國度的入口,你看到有極佳的防禦工事正在修築.無論任何時刻,矮
人在此地的武力都十分強大,因為這裡是通往矮人國度的唯一路徑.
CLong
);
set("exits",([
              "west":Deathland"/main/d7",
              "east":Deathland"/city/c2",
             ]));
set("objects",(["soldier#1":Monster"/soldier",
                "soldier#2":Monster"/soldier",
                "captain":Monster"/captain_1",
               ]) );
 create_door("west","east",([
             "c_desc" : "一扇結實厚重的石門",
             "keyword" : ({"stone door","door" }),
              "name" : "stone door",
             "desc" : "A stone door",
             "c_name" : "石門",
             "status":"closed",
              ]) );
  ::reset();
}
