#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("hoe","鋤頭");
    add("id",({"spade"}) );
    set_short("鋤頭");
    set_long(@C_LONG
這是一把鋤頭！
C_LONG
             );
    set("unit","把");
    set("type","longblade");
    set("weapon_class",5);
    set("min_damage",5);
    set("max_damage",10);
    set("weight",100);
    set("value",({20,"silver"}) );
 }

