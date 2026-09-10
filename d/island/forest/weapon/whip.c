#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Thunder Whip","雷神鞭");
    add("id",({"whip"}) );
    set_short("雷神鞭");
    set_long(@C_LONG
據說這是上古雷神魯特所持的神鞭。
C_LONG
            );
    set("unit","條");
    set("type","whip");
    set("weapon_class",13);
    set("min_damage",5);
    set("max_damage",10);
    set("second",1);
    set("value",({ 350,"silver"}) );
    set_c_verbs( ({"的%s如晴天霹靂般向%s直擊而去",
       "將%s甩成連綿不絕的圓圈圈卷向%s","的%s在地上游走不定，突然掃向%s"}) );
}    