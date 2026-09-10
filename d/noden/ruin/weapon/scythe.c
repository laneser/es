// scythe.c

#include "../lilia.h"

inherit WEAPON;

void create()
{
    set_name("Death Scythe", "死神鐮刀");
    add ("id",({ "scythe" }) );
    set_short("死神鐮刀");
    set_long("一把很十分鋒利的大鐮刀，據說是死神心愛的武器。\n");
    set("unit", "把");
    set("weapon_class", 42);
    set("type", "longblade");
    set("min_damage", 25);
    set("max_damage", 45);
    set("weight", 150);
    set("no_sale", 1);
    set("nosecond", 1);
    set("value", ({ 10, "silver" }) );
}

