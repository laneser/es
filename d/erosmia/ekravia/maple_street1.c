#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("Maple Street","楓樹大街");
	set_long(@Long
Long
,@CLong
你走在一條大街上, 兩旁各種著一排楓樹。幾片紅色的楓葉不時在你
的面前飄落, 別有一番情調。大街上並沒有多少人跡, 四周大多也是低矮
的平房, 使這裡顯得格外地恬靜。
    西邊有一條小路, 仔細傾聽, 似乎有些雞、鴨鳴叫的聲音由那邊傳來
CLong
);
	set("exits", ([
		"south"		: HERE"south_gate",
		"north"		: HERE"maple_street2",
		"west"		: HERE"small_road1"
		]));
}
