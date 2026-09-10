
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("palace2","神宮主殿");
       set_long(@C_LONG
富麗堂璜的擺設，一幅諾頓大陸的全圖彩繪就畫在天幕
上，令你不禁摒息注視這巧奪天工的黑暗精靈傑作，這就是
黑暗精靈村為紀念賽亞達所建造的大神宮，一座用紫水晶雕
成的雕像放在主殿前方，主殿牆上並掛了一面盾牌，上面繪
有耶拉曼皇室的符號，地上鋪有一塊毛絨絨的地毯，整個神
宮寧靜而安詳，光線柔和，但你不明白的是：這裡是地底王
城，但為何如此明亮？
C_LONG );
       set("exits",([
                     "west":"/d/noden/drow/r65",
                     "east":"/d/noden/drow/r67"
                    ]));
       set("light",1);
}
