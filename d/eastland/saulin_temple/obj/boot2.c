#include "../saulin_temple.h"
inherit ARMOR;

void create()
{
        set_name("silver dragon boots", "銀龍靴");
        add( "id", ({ "boots", "boot" }) );
        set_short("銀龍靴");
        set_long(@C_LONG
龍在中國乃祥瑞之兆, 銀龍靴相傳是天神賜給東方皇帝的天子之鞋, 
後由朝廷送給少林而後不幸遺失... 現在看起來又破又舊的。
C_LONG
        );
        set("unit", "雙");
        set("type", "feet" );
        set("armor_class", 8 );
        set("material","monk");
        set("defense_bonus", 3 );
        set("weight", 30 );
        set("value", ({ 2600, "silver" }) );
}
