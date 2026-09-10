#include "iigima.h"

inherit ROOM;

void create()
{

        ::create();
        set_short( "tunnel","廢棄通道");
        set_long(

@C_LONG
通過禁地之門，這裡一片荒蕪，四周結滿厚厚的蜘蛛網，地上到處是
灰塵，似乎很久沒有人來過了，咦？地上好像有幾片乾扁的蛇皮(skin)，
引起你的注意。
C_LONG
        );
        set( "exits", ([                     
                     "northwest": DROW"r36",
                     "southwest": DROW"r01",
        ]) );
       set("c_item_desc",(["skin":
@C_LONG
這些乾枯的蛇皮已經堆積了厚厚的一層了，看來這裡曾繁殖了不少
的蛇，有的蛇皮還蠻軟的，可能是有蛇剛蛻過皮吧。
C_LONG
]));
}
