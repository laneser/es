
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("???","河邊");
  set_long(@Long
Long
,@CLong
一處奇異的地方, 到處是你未曾見過的植物, 潮溼的地表以及令人掩鼻的氣味是這個
地方給你的感覺. 南面是一條流速極快的河川, 往北邊走應是一個蝙蝠洞, 除此之外你也
可以沿著河流行走.
CLong
);

set("c_item_desc",([
    "river":"一條流速極快的河川.\n",
           ]) );

set("exits",([
     "north":Deathland"/dwarf/batcave01",
     "east":Deathland"/dwarf/river02",
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
      write("這河水流動的太快速了,假如你真的下河去的話,\或許你可以直接遊\n"
            "到閻羅王的面前.\n");
    else {
      this_player()->move_player(Deathland"/dwarf/well05",({
      "%s swims river.\n","%s跳進了河中並努力地往對岸遊.\n",
      "%s appears from river.\n","%s從河中游上岸來.\n"}),"");
      write("你辛苦地游到了對岸.\n"); 
      }
    return 1;      
} 
