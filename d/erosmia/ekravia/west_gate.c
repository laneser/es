#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short( "西門" );
	set_long(@Long
這裡是愛卡拉維亞的西門, 道路往西進入山區, 最後通往山中的寶石
礦坑。回頭往東則是平靜的小鎮街道。
Long
);
	set("exits", ([
		"east"		: HERE"tinker_way5",
		"west"		: "/d/erosmia/9,10.erosmia",
		]));
}
