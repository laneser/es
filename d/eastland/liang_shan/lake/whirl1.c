#include "takeda.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        object ob;

	::create();
	set_short( "漩渦" );
	set_long(@C_LONG
這裡是巨大漩渦的底部，抬頭望去，扭曲的水流仍然聲勢驚人，使人心驚肉跳。
你感到仍然隱隱有股吸力，將你往上拉去，你感到腳底虛浮，心底想著最好還是
趕快離開此處。
C_LONG
	);
	set( "exits", ([
             "north" : TROOM"underwater2",            
	     "east" : TROOM"underwater3",
	     "south" : TROOM"underwater4"
	]) );
        set("underwater",1);
          reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
}



