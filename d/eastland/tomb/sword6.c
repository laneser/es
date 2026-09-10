#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("石室");
	set_long( 
@C_LONG_DESCRIPTION
你進入了一個小小的石室，與外面比起來，這兒真是小的微不足道。四周空無一物，只
有一根蠟燭孤獨地點在牆邊。
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([ 
		"south" : TOMB"/sword4",  ]) );
	set( "objects", ([
		"swordman" : MOB"/sword_soul" ]) );
	reset();	
#include <replace_room.h>
}

