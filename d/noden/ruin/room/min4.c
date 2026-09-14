// min4.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("神殿祭壇");
    set_long(@C_LONG
你的前方有個一個六芒星狀的黑色祭壇，六芒星的尖端各立著一根白色的
蠟燭，祭壇上有著幾個暗紅色的符號 (alphabet) ，似乎是用血塗上去的。你
仔細一看，六芒星的中心似乎有被火燒過的痕跡。
C_LONG
    );
    set("objects", (["archbishop" : MOB"archbishop"]));
    set("exits", ([
	"north" : AREA"min5",
	"south" : AREA"min3"
	]) );
    set("pre_exit_func", ([ "north" : "exits_open" ]));
    reset();
}

int exits_open()
{
    if (present("archbishop",this_object()))
    {
	if (this_player()->query_temp("lilia_pass") >= 2)
	    return 0;
        write ("大祭司擋住你的去路並且說道：對不起，先打倒我才能向前走。\n");
        return 1;
    }
    else return 0;
}

