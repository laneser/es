// camp.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("帳蓬內部");
    set_long(@C_LONG
這裡是帳蓬的內部，帳蓬的頂上懸著一盞昏暗的油燈，牆角堆置著許多書
籍，看來這裡的主人不但是個有學問的人，而且已經住在這裡很久了。你注意
到了牆上掛著一幅奇怪的碑文 (rune) 拓片。
C_LONG
    );
    set("exits", (["out" : AREA"rose1"]) );
    set("light", 1);
    set("objects", (["explorer" : MOB"deltazeus"]) );

    reset();
}
 
