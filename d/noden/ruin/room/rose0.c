// rose0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("廢墟");
    set_long(@C_LONG
你來到了一個破舊的廢墟，到處散落著頹圮的石柱和石塊。地上似乎有條
小徑通往北方，你不禁覺得奇怪，這個鳥不生蛋的地方除了你這麼無聊的人之
外還有誰會來呢？
C_LONG
    );
    set("exits", (["north" : AREA"rose1"]) );

    reset();
}
