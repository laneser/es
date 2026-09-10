
#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "鐘乳石洞穴" );
	set_long(@LONG
你忽然來到一處潮溼的洞穴，叮叮咚咚的水聲由洞穴深處傳來。
猛抬頭一看，幾根將近三尺的鐘乳石上，忽然落下幾滴清涼的水珠打
在你身上。剎時間你覺得彷佛置身仙境。
LONG
		);
	set( "exits",([ 
			"southwest" : HOLE"water19",
			"southeast" : HOLE"water21",
		]) );
	reset();
	
}