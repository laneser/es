#include "../ekravia.h"

inherit MONSTER;

void create()
{
	object	hat, coat, pants;

	::create();
	set_level(9);
	set_name( "wounder magician", "魔術師" );
	add( "id", ({ "magician" }) );
	set_short( "流浪魔術師" );
	set_long(@LONG
專門帶給眾人歡笑的魔術師。他的身材普通, 身穿一套黑色的燕尾服, 頭
上戴著註冊商標般的黑色高帽子。靈巧的手配合著略顯誇張的表情, 流暢
地演出著令人歎為觀止的魔術。
LONG
	);
	set_perm_stat( "str", 7 );
	set_perm_stat( "dex", 9 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "con", 7 );
	set_perm_stat( "pie", 10 );
	set_natural_weapon( 20, 9, 19 );
	set_natural_armor( 25, 9);
	set( "gender", "male" );
	set( "alignment", 200 );
	set( "wealth/silver", 100 );
	
	hat = clone_object( OBJ"black_hat" );
	coat = clone_object( OBJ"coat" );
	pants = clone_object( OBJ"pants" );
	hat->move(this_object());
	coat->move(this_object());
	pants->move(this_object());
	equip_armor(hat);
	equip_armor(coat);
	equip_armor(pants);

	set( "chat_chance", 15 );
	set( "chat_output", ({
		"魔術師摘下帽子, 向在場所有觀眾鞠了個恭。\n",
		"突然間, 兩隻鴿子從帽子裡飛了出來, 又飛進帽子, 又飛出來, 但飛出來"
		"的卻是八隻。\n",
		"魔術師倒倒帽子, 示意裡面空空如也。\n",
		"魔術師右手輕輕一揮, 一個氣球飛了出來, 飄向廣闊的天空。\n",
		"魔術師兩手一揚, 地上爆起一陣煙霧, 在煙霧散去後只見那頂高帽子倒放"
		"在地, 人消失了。\n",
		"一大堆的鴿子毫無預警地由帽子裡飛出, 帶著一堆綵帶, 後面跟著魔術師"
		"本人\n－從帽子裡爬了出來。\n",
		"眾人給予魔術師熱烈的掌聲, 紛紛把錢丟進他的高帽子裡。\n"
	}) );
}
