#include "../ekravia.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "smith", "鐵匠" );
	add( "id", ({ "smith" }) );
	set_short( "鐵匠" );
	set_long(@LONG
一個身材魁武的大漢, 穿著短袖上衣, 滿身大汗地在鼓風爐旁工作著。
LONG
	);
	set( "gender", "male" );
	set( "alignment", 100 );
	set( "wealth/silver", 300 );
	set( "no_attack", 1 );
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"鐵匠使勁地把空氣送進爐子裡, 一時間爐火大盛, 整個房間都熱了起來。\n",
		"鐵匠由爐中取出燒紅的鐵水, 將其倒進模子裡成形。\n",
		"鐵匠用特別的槌子一槌一槌地敲打炙熱的刀身, 將多餘的雜質打出來。\n",
	}) );
}
