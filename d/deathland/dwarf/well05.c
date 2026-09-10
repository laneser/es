
#include "../echobomber.h"

inherit ROOM;

int squ;
void create()
{
	::create();
  set_short("well","地下河道");
  set_long(@Long
Long
,@CLong
四周到處都是青苔和一些奇怪的小蟲,而且這裡的泥土十分潮□,似乎這裡是地下
河川的河道,但是目前這河道已經乾枯了.而在你的北邊有一條很大的地下河川(river)
,河水流動地非常快速. 這裡的西南角有個破舊的建築,它的牆壁已經塌陷了,似乎很久
沒有人到過那裡.
CLong
);

set("c_item_desc",([
    "river":"一條流速極快的河川.\n",
           ]) );

set("exits",([
     "east":Deathland"/dwarf/well03",
     "southwest":Deathland"/dwarf/prison",
     ]) );
 ::reset();
}

void init()
{
   add_action("to_swim","swim");
}

int to_swim()
{
    int swim;
    swim=this_player()->query_skill("swimming");
    if ( swim<50 )
      write("這河水流動的太快速了,假如你真的下河去的話,或許你可以直接遊\n"
            "到閻羅王的面前.\n");
    else {
      this_player()->move_player(Deathland"/dwarf/river01",({
      "%s跳進了河中並努力地往對岸遊.\n",
      "%s從河中游上岸來.\n"}),"");
      write("你辛苦地游到了對岸.\n"); 
      }
    return 1;      
} 
