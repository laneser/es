#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Sikoku chianmail","黑麵血甲");
    add("id",({"sikoku","chainmail","mail"}) );
    set_short("黑麵血甲");
    set_long(@C_LONG
為了得到黑暗的加護，用黑血染成的鎧甲，是戰場的不祥物之一。
C_LONG
    );

    set("unit","件");
    set("type","body");
    set("material","light_metal");
    set("weight",100);
    set("armor_class",20);
    set("defense_bonus",2);
    set("value",({500,"silver"}) );
}
