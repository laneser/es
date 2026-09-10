#include "../ekravia.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Dino", "迪諾" );
	add( "id", ({ "dino" }) );
	set_short( "旅店老闆  迪諾" );
	set_long(@LONG
一個身材高大的中年人, 全身上下散發出一種堅毅與勇敢的氣質, 二十年
前的他應該是個極為出色的騎士吧? 不知為何這樣的人會在這裡默默地經
營一家旅店。
LONG
	);
	set_perm_stat( "str", 27);
	set_perm_stat( "dex", 23 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "con", 25);
	set_perm_stat( "pie", 15 );
	set( "natural_armor_class", 100 );
	set( "natural_defense_bonus", 20 );
	set( "max_hp", 1000 );
	set( "hit_points", 1000 );
	set( "gender", "male" );
	set( "alignment", 800 );
	set( "wealth/silver", 5000 );
	set( "no_attack", 1);

	set( "chat_chance", 15 );
	set( "chat_output", ({
		"老闆坐在櫃檯前, 默默地翻閱著手上的書籍。\n",
		"老闆望了你一眼, 沈穩地問道「這位客人, 您是要住一晚嗎?」\n",
		"老闆拿著抹布, 輕輕地擦拭著櫃檯旁邊的架子。\n"
	}) );
}
