#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Combat Cap","戰鬥冠");
    add("id",({"hat","cap"}) );
    set_short("戰鬥冠");
    set_long(@LONG
這是一件輕巧精緻的帽子。
LONG
            );
    set("unit","件");
    set("type","head");
    set("material","wood");
    set("armor_class",5);
    set("defense_bonus",2);
    set("weight",100);
    set("value",({300,"silver"}) );
}
