// translation done -Elon 03-10-94 (desc is kinda dumb, I know..)
#include "../moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("育嬰室");
	set_long( @C_LONG_DESCRIPTION
這裡看起來是怪蟻的育嬰室，好多隻小螞蟻正在哭著，工蟻們正把一種
黃褐色的液體喂入小螞蟻的口中。
C_LONG_DESCRIPTION
	);
	set( "exits", ([
	   "west"   : MOYADA"anthill/square",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant baby#1"   : MOYADA"monster/ant_baby",
	   "ant baby#2"   : MOYADA"monster/ant_baby",
	   "ant baby#3"   : MOYADA"monster/ant_baby",
	   "ant baby#4"   : MOYADA"monster/ant_baby",
	   "ant baby#5"   : MOYADA"monster/ant_baby",
	   "ant baby#6"   : MOYADA"monster/ant_baby",
	]) );
	reset();
}

void reset()
{
    set( "ant_left", 6);
    ::reset();
}
