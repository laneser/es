#include "iigima.h"
inherit ROOM;

void create()
{

        ::create();
        set_short( "hilove temple","希魯芙神殿");
        set_long(
        @C_LONG
廣大的空間，挑高有３０米吧，你看了不禁為黑暗精靈族的建築技術
感到訝異，這裡是黑暗精靈村落四大神殿中最大的一間，四周燈火通明，
牆上雕有很多的蜘蛛圖案，而中央的大平臺上，有一尊很大的神像
(statue)，祥和而安寧的模樣，似乎不是黑暗精靈所供奉的邪神。
牆邊的蜘蛛圖案上有一個板手(lever)，似乎怪怪的。
C_LONG
        );

        set( "light",0 );
        set( "exits", ([

                     "east": DROW"r18",
        ]) );
        set("search_desc",([
                   "lever": "@@to_search_lever"
          ]) );
        set("c_item_desc",(["statue":

@C_LONG
這是黑暗精靈膜拜的風之女神－希魯芙的雕像，開展的雙翼彎曲
地遮住了半個神殿的面積，看來栩栩如生的樣子。
C_LONG
,
            "lever":
@C_LONG
這個板手斜插入一個小小黑黑的螺孔內，看來是某個通道的機
關吧。
C_LONG
           ]));
        set("objects", ([
              "m7": DRO"chim"
        ]) );
        reset();
}
int to_search_lever()
{
     write("哇～你感到一陣天旋地轉，好像來到另一個地方了。\n");
     this_player()->move_player(DROW"r26","SNEAK");
     return 1;
}
