#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Holy Hat","聖光帽");
    add("id",({"hat","cap"}) );
    set_short("聖光帽");
    set_long(@LONG
這是一件充滿魔力的帽子，只見金光閃閃，彷佛是擁有取之不竭、用之不盡的強大能源
似的。
LONG
            );
    set("unit","件");
    set("type","head");
    set("material","wood");
    set("armor_class",6);
    set("defense_bonus",1);
    set("weight",100);
    set("value",({400,"silver"}) );
}
