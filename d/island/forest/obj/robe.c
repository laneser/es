#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Holy Robe","聖光袍");
    add("id",({"robe"}) );
    set_short("聖光袍");
    set_long(@LONG
這是一件充滿魔力的法袍，只見金光閃閃，彷佛是擁有取之不竭、用之不盡的強大能源
似的。
LONG
            );
    set("unit","件");
    set("type","body");
    set("material","wood");
    set("armor_class",25);
    set("defense_bonus",2);
    set("weight",200);
    set("value",({700,"silver"}) );
}
