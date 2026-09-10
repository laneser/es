#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Snow Gloves","雪護手");
    add("id",({"gloves"}) );
    set_short("雪護手");
    set_long(@C_LONG
雪神獸白虎的皮毛所製成的護手，可以造成冷氣障礙壁壘。
C_LONG
    );

    set("unit","雙");
    set("type","hands");
    set("material","light_metal");
    set("weight",30);
    set("armor_class",4);
    set("defense_bonus",1);
    set("value",({500,"silver"}) );
}
