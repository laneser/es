#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Combat Robe","戰鬥法袍");
    add("id",({"robe"}) );
    set_short("戰鬥法袍");
    set_long(@LONG
這是件輕巧精緻的法袍。
LONG
            );
    set("unit","件");
    set("type","body");
    set("material","wood");
    set("armor_class",21);
    set("defense_bonus",1);
    set("weight",80);
    set("value",({700,"silver"}) );
}
