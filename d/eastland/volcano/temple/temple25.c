#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿後殿");
	set_long( 
@LONG_DESCRIPTION
一間迷漫著神秘氣氛的矮靈族神殿後殿，神殿的頂端雕有火鳳凰的圖案，
這裡供奉的是火鳳凰，在矮靈族的傳說中火鳳凰是火神的坐騎之一。
往南是神殿重地，閒雜人等不能進入。
LONG_DESCRIPTION
	);
set( "exits", ([
     "south":OTEMP"temple25",
     "northeast": OTEMP"temple24",
     "northwest": OTEMP"temple23",
     ]) );
set( "pre_exit_func", ([
     "south":"to_south" ]) );
reset();
}

int to_south()
{
  if (((this_player()->query_quest_level("Dragon_box"))>0)||(this_player()->query("npc"))) {
    this_player()->move_player(OTEMP"temple26","SNEAK");
    return 1;
  }
  write("\n\n火鳳凰從屋頂飛了下來，擋在你的面前說：對不起，以你的能力不能夠進去。\n\n");
  return 0;
}
