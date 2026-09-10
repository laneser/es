#include "../ekravia.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "old alchemist", "鍊金術師" );
	add( "id", ({ "alchemist" }) );
	set_short( "老鍊金術師" );
	set_long(@LONG
你看到一個穿著白色長袍的老者, 左手上正好拿著一個燒瓶。他看來正忙
著某種實驗。大約是發現你的到來吧? 他停下手邊的工作, 回過身來對著
你微笑。
LONG
	);
	set( "gender", "male" );
	set( "alignment", 500 );
	set( "wealth/silver", 1000 );
	set( "no_attack", 1 );
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"老鍊金術師親切地問道:「需要什麼嗎? 年輕人」\n",
		"老鍊金術師回頭埋首於他的實驗。\n",
		"老鍊金術師說道:「這裡有不少上好的藥劑, 自己參考一下清單吧!」\n",
	}) );
}
