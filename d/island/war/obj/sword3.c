#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name("Koku Sword","黑王劍");
    add("id",({"koku","sword"}) );
    set_short("黑王劍");
    set_long(@C_LONG
是傳說中魔人黑王的劍，他會吸食失敗者的血，所以早已化為
半妖劍。
C_LONG
    );

    set("unit","柄");
    set("weight",150);
    set("type","longblade");
    set("weapon_class",30);
    set("min_damage",12);
    set("max_damage",32);
    set("value",({600,"silver"}) );
}
