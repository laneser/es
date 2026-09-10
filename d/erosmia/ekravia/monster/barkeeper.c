#include "../ekravia.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "barkeeper", "酒保" );
	add( "id", ({ "barkeeper" }) );
	set_short( "酒保" );
	set_long(@LONG
他擦洗著杯子, 等著下個顧客來點酒, 偶而與前面的顧客低聲交談。
酒吧的酒保總是附近消息最靈通的人。
LONG
	);
	set( "gender", "male" );
	set( "alignment", 50 );
	set( "no_attack", 1);

	set( "chat_chance", 15 );
	set( "chat_output", ({
		"酒保默默地擦洗著杯子。\n",
		"一個前面的客人向酒保要了杯酒, 酒保點了點頭, 開始調起酒來。\n",
	}) );
	
	set( "inquiry", ([
		"rumor" :	
		"最近沒什麼消息, 只聽說最近楓樹大街上有奇怪的幽靈(phantom)出沒。",
		"phantom" :	
		"這我不是很清楚, 不過酒鬼沙理斯宣稱他曾經看過。哼, 誰會相信一個酒\n"
		"鬼的醉言醉語呢?",
	]) );
}
