// trans. done -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("廣場");
	set_long( @C_LONG_DESCRIPTION
很難得在地下有這麼大的一片廣場，西邊和南邊各有一條通道，更多的
螞蟻正在忙碌的搬運一些圓圓的東西，看起來像是蟻卵。
C_LONG_DESCRIPTION
	);
	set( "exits", ([
	   "west"   : MOYADA"anthill/check_point",
       "east"   : MOYADA"anthill/baby_room",
       "south"  : MOYADA"anthill/queen_room",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant guard" : MOYADA"monster/ant_guard",
	   "kaisa ant" : MOYADA"monster/kaisa_ant",
	]) );
	reset();
}

void reset()
{
    set( "ant_left", 4);
    ::reset();
}
