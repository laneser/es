#include <mudlib.h>
#include <conditions.h>

inherit ROOM;

void create()
{
    ::create();
    set_short("河中");
    set_long(@LONG
在這潺潺的小河中看，只覺得一切都好乾淨、好清晰，頭頂上的光透過
波浪，映在底下的沙地上，使人感覺彷佛置身於塵囂之外，那另一個未曾探
索過的世界一般。這令人流連的境地，讓你幾乎忘了要呼吸了！
LONG
            );
    set("exits",([
        "north":"/d/noden/11,5.noden",
        "south":"/d/noden/11,7.noden"]) );
    set("underwater",1);
    reset();
}

void init()
{
    UNDERWATER->apply_effect(this_player(),3,2);
}
