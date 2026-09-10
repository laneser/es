// wenro1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("峽谷的底部");
    set_long(@C_LONG
你來到了一個峽谷的底部，橫在你面前的是一條清徹的河流，映著兩岸高
聳峭壁的倒影，你不由得由心中讚歎起這美麗的造物主傑作。你身後的巖壁上
掛滿了慵懶地垂著的藤蔓，藤蔓的後面似乎藏著有字。
C_LONG
    );
    set("exits", (["west" : AREA"wenro2"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
    add_action("to_swim", "swim");
}

int to_search()
{
    write("巖壁上寫著：響應大家來飛行運動，請勿在此游泳。\n");
    return 1;
}

int to_swim()
{
    write("你不費吹灰之力地游到了對岸 ....\n");
    this_player()->move(AREA"wenro0");
    return 1;
}

