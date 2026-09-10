#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("洞穴");
	set_long( @C_LONG_DESCRIPTION
你進入了山壁上的洞穴，洞穴的四周插滿了火把，照的四周一片明亮，許多山賊
在洞穴裡鑽來鑽去，只有少數人注意到你的進入而投以懷疑的目光。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"out" : TROOM"yard1", 
		"eastdown" : TROOM"cave4" ]) );
	reset();
}
int clean_up() { return 0; }