#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "長長的巖隙" );
	set_long(
	"這是在山間自然生成的巖隙，兩旁緊迫的山璧使你有一種透不過氣的感覺，\n"
	"一條條的鐘乳從你的頭頂垂下，雖然你一方面讚歎大自然的鬼斧神工，另一\n"
	"方面你卻又暗自咒罵它們使你的通行更加困難。再加上地上溼漉漉的，你必\n"
	"須更小心的前進以免滑倒。巖隙的盡頭有個小洞，好像可以離開此處。\n"
	);
        set("c_item_desc",(["hole":
        "一個小洞，可以通到外面去，假使你不太胖的話，應該可以擠(squeeze)\n"
        "的出去，不過這個洞蠻長的，因此你無法得知外面的環境如何。 \n"
                ]));
        set( "exits", ([
                   "squeeze" : TROOM"underjail4",
                   "northwest" : TROOM"underjail2"
                   ]));
        set("exit_suppress", ({ "squeeze" }) );                 
        set("pre_exit_func",([
            "squeeze":"pass_hole",
                ]) );
        reset();
}
int pass_hole()
{
    write("你把頭伸進小洞，擠呀擠呀，終於給你擠出去了....\n");
    write("碰的一聲....你重重的摔在地上\n");
    this_player()->receive_damage(10);
    return 0;
}
int clean_up() { return 0; }