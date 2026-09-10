#include "../tsunami.h"
inherit WEAPON;

void create()
{
    set_name("Regular spear","制式長矛");
    add("id",({"spear"}) );
    set_short("制式長矛");
    set_long(@LONG
這是一把魔族軍通用的長矛．
LONG
            );
    set("unit","把");
    set("type","thrusting");
    set("weapon_class",15);
    set("min_damage",10);
    set("max_damage",18);
    set("weight",150);
    set("value",({150,"silver"}) );                
}