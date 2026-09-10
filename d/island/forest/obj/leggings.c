#include "../tsunami.h"

inherit ARMOR;

void create()
{
     set_name("Combat Skirt","樹雷戰鬥圍裙");
     add("id",({"skirt"}) );
     set_short("樹雷戰鬥圍裙");
     set_long(@LONG
這是一條繡有樹雷王家家徽的圍裙，聽說那家徽總是能帶給人幸運，因此王族特別
喜愛將它編織在各種衣物或飾品上；這條圍裙上的家徽看起來更是亮麗，想必能給
於使用者特別完美的保護吧！
LONG
             );
     set("unit","條");
     set("weight",100);
     set("material","element");
     set("type","legs");
     set("armor_class",8);
     set("defense_bonus",3);
     set("value",({200,"gold"}) );
}
