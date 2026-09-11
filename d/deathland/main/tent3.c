// /u/e/echobomber/deathland/tent3.c

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("寂靜的帳篷");
 set_long(@Long
一個非常安靜的帳篷,與外界完全隔離著,當你一踏進這個地方時,就覺得
似乎有個魔法力場籠罩著整個地方.
Long
	);
       set("exits",(["out":Deathland"/main/d11",
                    ]));
       set("objects",(["retal":Monster"/retal",
                      ]));
       reset();
#include "../replace_room.h"
}

