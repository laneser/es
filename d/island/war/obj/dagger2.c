#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name(" Prick","破魔錐");
    add("id",({ "dagger" }) );
    set_short("破魔錐");
    set_long( @C_LONG
這是魔族魔導士專用的武器，輕巧的設計使他成為戰爭中的利器。
C_LONG
            );
    set("unit","把");
    set("weapon_class",17);
    set("type","dagger");
    set("min_damage",10);
    set("max_damage",19);
    set("weight",50);
    set("value", ({400,"silver"}) );
}
