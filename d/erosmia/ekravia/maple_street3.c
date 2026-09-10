#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_outside();
	set_short("Maple Street","楓樹大街");
	set_long(@CLong
你走在大街上, 四周人來人往, 相當熱鬧。街道兩旁蓋滿了漂亮的兩
層式洋房, 樓下開了各式各樣的商店。路旁還有許多小販叫賣著剛從田裡
採來的新鮮蔬菜。
    吟遊詩人之家就在大街東邊, 兩棵美麗的紅楓之間。正對面正好是一
家古老的旅店 (tavern), 同時也是鎮上最好的酒吧。
CLong
);
	set("exits", ([
		"south"		: HERE"maple_street2",
		"north"		: HERE"maple_street4",
		"west"		: HERE"tavern",
//		"east"		: HERE"bard_guild",
		]));
}
