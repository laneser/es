#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "merchant", "路邊賣蚵仔煎的" );
	add( "id", ({ "merchant" }) );
	set_short( "路邊賣蚵仔煎的" );
	set_long(@C_LONG
一位賣蚵仔煎的路邊小販，他正滿頭大汗地招覽客人。
C_LONG
        );
	set( "gender", "male" );
        set( "wealth/silver",100);
        set_natural_armor(55,2);
        set_natural_weapon( 19,10,20 );
        set("chat_chance",3);
        set("chat_output",({
            "來喲，趕緊來吃好好吃的蚵仔煎喲。\n"
        }) );
        set( "inquiry", ([
            "fly_building":"@@ask_building",
        ]) );
}
void ask_building(object asker)
{
tell_room(environment(),@LONG

賣蚵仔煎的說道：天都？我以前好像有看過喔．．對了，我曾經路過城外南
　　　　　　　　邊的山嶺上看過一棟漂浮在空中的建築物，不曉得是不是
　　　　　　　　你所說的天都？不過，你可以去請教郊外一家草蘆的老人
　　　　　　　　家名叫「金石老人」(golden_older)，他常說他年輕時到
		過天都。唉喲，先不要管這個，你要不要來盤蚵仔煎啊？　　
　　
LONG
   );
}
