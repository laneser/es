// eda6.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("依達波第亞宮．邊廂");
    set_long(@C_LONG
這裡是依達波第亞宮的邊廂，到處散落著毀壞的石柱和瓦片，看來魔族一
定遭遇了極為可怕的災難，才會造成這麼悽清的景象。這地方應該也已荒廢了
一段很長的時間了。
C_LONG
    );
    set("exits", ([ "west" : AREA"eda4" ]) );
    reset();
}

