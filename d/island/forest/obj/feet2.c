#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Cloth feet","布鞋");
    add("id",({"boots","boot","feet"}) );
    set_short("布鞋");
    set_long(@LONG
這是樹雷王家傳統的布鞋，它的長相和一般的襪子有些類似，但是可以直接當
做鞋子穿！
LONG
            );
    set("unit","雙");
    set("type","feet");
    set("material","cloth");
    set("armor_class",3);
    set("defense_bonus",0);
    set("weight",50);
    set("value",({10,"silver"}) );
}