#include <mudlib.h>
#include "academy.h"

inherit ROOM;

void create()
{
	::create();
    set( "max_laod", 100000 );
	set( "light", 1 );    	
	set_short( "Academy of Wizards", "巫師學院" );
	set_long( @LONG
It needs work here.	
LONG
, @C_LONG
你現在正站在巫師學院的大門, 年輕的實習巫師們在這裡學習如何將
他們們的構想實現出來, 同時也接受學校中的種種考驗。在他們通過學校
中所有的考驗的同時, 他們就擁有成為正式巫師的資格。
C_LONG
	);
	set( "exits", ([
		"north"  : HERE"hall"
	]) );
}
