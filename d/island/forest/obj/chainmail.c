#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Wind Chainmail","魔風之鎧");
    add("id",({ "chainmail","mail"}) );
    set_short("魔風之鎧");
    set_long(@LONG
這是魔族利用古魔法所創造出來的精緻鎧甲.
LONG
            );
    set("unit","件");
    set("type","body");
    set("material","element");
    set("armor_class",25);
    set("defense_bonus",2);
    set("special_defense",(["fire":20,"cold":20]) );
    set("weight",250);
    set("value",({300,"gold"}) );
}
