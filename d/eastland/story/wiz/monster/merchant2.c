#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "merchant", "路邊賣米粉羹的" );
	add( "id", ({ "merchant" }) );
	set_short( "路邊賣米粉羹的" );
	set_long(@C_LONG
一位賣米粉羹的路邊小販，他正滿頭大汗地招覽客人。
C_LONG
        );
	set( "gender", "male" );
        set( "wealth/silver",100);
        set_natural_armor(55,2);
        set_natural_weapon( 19,10,20 );
        set("chat_chance",3);
        set("chat_output",({
            "來喲，來吃香噴噴好好吃的米粉羹喲。\n"
        }) );
        set( "inquiry", ([
             "entrance_palace":"@@ask_enter",
        ]) );
}
void ask_enter(object asker)
{
tell_room(environment(),@LONG

賣米粉羹的說道：喔，你想要進去皇宮咩？我是不太清楚啦，不過，你可以去
　　　　　　　　請教大官看看。先不要管這個，你要不要來一碗米粉羹啊？

賣米粉羹喊道："來喲，來吃香噴噴好好吃的米粉羹喲。\n"

LONG
   );
}
