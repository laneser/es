// something wrong with this room.. I dunno ;)  -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("王室");
	set_long( @C_LONG_DESCRIPTION
這裡大概就是蟻后住的地方，並未顯得富麗堂皇，只不過氣氛顯得有些
嚴肅。蟻后龐大的身軀幾乎佔滿了整個房間，幾隻工蟻正在忙著把她產下的
卵運出去。
C_LONG_DESCRIPTION
	);
	set( "exits", ([
      "north"  : MOYADA"anthill/square",
	]) );
	set( "no_monster", 1);
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant queen" : MOYADA"monster/ant_queen",
	   "kaisa ant#1" : MOYADA"monster/kaisa_ant",
	   "kaisa ant#2" : MOYADA"monster/kaisa_ant",
	]) );
	reset();
}

void reset()
{
    set( "ant_left", 5);
    ::reset();
}
