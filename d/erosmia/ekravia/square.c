#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("中心廣場");
	set_long(@Long
這裡是整個愛卡拉維雅鎮的心臟地帶, 東西向的工匠小徑與往南延伸
的楓樹大街在此交會, 形成一個大廣場。許多的小販旅行商人們在這裡交
易著工藝品與食物。幾個旅行藝人或是魔術師在此賣藝, 不時引出陣陣的
歡笑聲。
    廣場的北邊是鎮長的公館, 也是整個鎮上最豪華的的一棟建築。
Long
);
	set("exits", ([
		"south"		: HERE"maple_street4",
		"east"		: HERE"tinker_way3",
		"west"		: HERE"tinker_way4",
		]));
	set( "objects", ([
		"magician"	: MOB"magician",
		"vendor"	: "/obj/vendor",
		]) );
	reset();
}
