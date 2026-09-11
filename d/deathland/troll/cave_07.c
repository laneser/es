
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("Troll Altar","巨人祭壇");
        set_long(@Long
Long
,@Clong
這裡似乎是一個屠宰場,但是兩旁卻有許許多多奇奇怪怪的圖騰矗立著,以
及一個很巨大的塑像立在你的面前,山頂巨人常常用活生生的人,去祭祀祈求戰
爭殘殺的勝利.
Clong
	);
set("exits",([
   "east":Deathland"/troll/cave_06",
            ]) );
::reset();
#include "../replace_room.h"
}

void init()
{
  this_player()->set_explore( "deathland#2" );
}

