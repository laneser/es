// translation done -Elon 03-10-94
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("招待室");
	set_long( @C_LONG_DESCRIPTION
這裡看起來像是這些怪蟻們接待客人的地方，你很懷疑它們會有什麼客人?
也許是其他國度的蟻類吧。奇怪的桌子上放著一些麵包 (bread)和乳酪(butter)
，好像可以吃的樣子。桌子旁坐著幾隻奇怪的紅色螞蟻。
C_LONG_DESCRIPTION
	);
	set( "item_desc", ([
      "bread" : "一些吃剩的麵包，看起來似乎可以吃。\n",
      "butter" : "已經發酵了的乳酪，聞起來臭臭的。\n",
    ]) );
	set( "exits", ([
		"south" : MOYADA"anthill/cellar1",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant waiter" : MOYADA"monster/ant_waiter",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set("ant_left",5);
}
