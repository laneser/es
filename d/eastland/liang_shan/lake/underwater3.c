#include "takeda.h"
#include <conditions.h>

inherit ROOM;

void create()
{
        object ob;

	::create();
	set_short( "湖底" );
	set_long(@C_LONG
這裡是大湖的湖底，從水面上透入淡淡的天光，搖曳的光影投影在平坦的沙底
，形成了一幅奇特的情景。從水底向上仰望，隱約可以看到水面上的風景，平沙上
躺著幾節枯木，造型奇特，但你卻沒有時間好好欣賞。因為你知道，不趕快離開此
處的話，你就要永遠的躺在湖底了。
C_LONG
	);
	set( "exits", ([
             "up" : TROOM"deep3",            
	     "west" : TROOM"whirl1",
	     "south" : TROOM"underwater5"
	]) );
        set_outside("eastland");
        set("underwater",1);
          reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
}



