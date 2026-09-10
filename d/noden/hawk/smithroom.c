
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("鐵匠鋪");
        set_light(1);
        set_long( @LONG_DESCRIPTION
這裡是天空之城唯一的鐵匠鋪，店裡的老鐵匠在這邊工作二十多年了，為鳥人
族人所打造的眾多武器使得鳥人戰士們得以一次次擊退蠢蠢欲動心懷不軌的異族，
因此老鐵匠的地位相當崇高。
    牆上掛著一張精美絕倫的圖片，上面畫的是奧林帕斯山上眾神(god) 在宴會里
的享樂的情形，跟周圍忙亂的情形相比，顯得很不搭調。
LONG_DESCRIPTION
        );

        set( "objects", ([
                "smith" : MOB"smith"
                        ]) );

        set( "exits", ([
                "out" : HAWK"room2-16",
                     ]) );
    reset();
}//end of creat

