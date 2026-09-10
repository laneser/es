#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Wind Dagger","風刃匕首");
    add("id",({ "dagger" }) );
    set_short("風刃匕首");
    set_long( @C_LONG
這是一把精心設計的匕首，鋒利的刀刃泛著閃亮的青光，彷佛在渴望著要吸食生血。
C_LONG
            );
    set("unit","把");
    set("weapon_class",25);
    set("type","dagger");
    set("min_damage",15);
    set("max_damage",22);
    set("weight",50);
    set("value", ({400,"silver"}) );
}
