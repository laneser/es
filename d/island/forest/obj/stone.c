#include <mudlib.h>

inherit CONTAINER;

int left_hole,mid_hole,right_hole;

void create()
{
    ::create();
    set_name("Stone","破邪鎮");
    set_short("破邪鎮");
    set_long(@C_LONG
一棵巨大的天然巖塊，巖塊上有三個大小不同的小洞洞(hole)，
好像可以插(insert)東西耶!!
C_LONG
            );
    set("prevent_get",1);
}

