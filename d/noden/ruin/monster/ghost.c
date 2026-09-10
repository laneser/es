// ghost gardener

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name("ghost", "鬼魂");
    set_short("鬼魂");
    set_long(@C_LONG
這團模糊的白影，手上似乎拿著小水瓢和花剪，它生前或許就是這兒的園
丁吧！究竟是什麼原因讓他在這裡逗留沒到奈何橋去報到呢？或許靜心觀察一
下會有些收穫也說不定。
C_LONG
	    );
    set("chat_chance", 15);
    set("chat_output", ({"鬼魂說：前頭是受詛咒的死亡迷宮，還是快回頭吧!\n"}));
    set("no_attack", 1);
    set("gender", "male");
    set("race", "undead");
    set("unit", "位");
}
 

