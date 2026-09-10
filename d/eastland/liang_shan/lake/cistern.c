#include "takeda.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        object ob;

	::create();
        set_short( "水缸之中" );
	set_long(@C_LONG
這裡是水缸裡面，大小剛好夠你把整個身子埋進水裡，或許是因為這兒沒幾個
人來過，你發現缸中的魚兒正好奇的打量著你。
C_LONG
	);
	set( "exits", ([
	     "out" : TROOM"room2"
	]) );
        set( "objects",([
             "fish1" : TMONSTER"fish11",
             "fish2" : TMONSTER"fish11",
             "fish3" : TMONSTER"fish11"]));
        set("underwater",1);
          reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
}



