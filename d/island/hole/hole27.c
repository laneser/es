#include "hole.h"

inherit ROOM;
void create()
{
	::create();
	set_short( "綠苔廣場" );
	set_long(@LONG
洞穴到這兒似乎變得寬闊多了，兩旁牆壁上掛著許多火把，使人能
很清楚的看到這個大石洞中的一切。哦～～！原來這兒是蜥蜴人平時聚
會的廣場，由於石壁上長滿了淡綠色的青苔，故得名「綠苔廣場」。
LONG
		);
	set( "light",1 );
	set( "exits",([
			"west"  : HOLE"hole24",
			"south" : HOLE"hole28",
			"north" : HOLE"hole26"
			]) );
	reset();
#include <replace_room.h>
}
