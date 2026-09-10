#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Hawk Cloak","光鷹鬥蓬");
    add("id", ({ "cloak","soup" }) );
    set_short("光鷹鬥蓬");
    set_long(@C_LONG
這是樹雷王家成員戰鬥時專用的披風。當王族穿上此披風時，防禦力將會倍增。加上
由於質地輕巧，無形中增加了機動力，所以成為王族的最愛。可不要小看這件披風哦
，它可是收集罕見的『光鷹羽』所織成的哦！
C_LONG
           );
    set("unit","件");
    set("type","cloak");
    set("material","leather");
    set("armor_class",8 );
    set("defense_bonus",4 );
    set("special_defense", (["fire":10,"cold":10,"divide":-20,"poison":-30]) );
    set("weight",100);
    set("value",({1200,"silver"}) );
}
