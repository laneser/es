#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name("Light Sword","魔獸劍");
    add("id",({"sword"}) );
    set_short("魔獸劍");
    set_long(@LONG
這是魔獸所幻化而成的光劍，你能擁有這光芒耀眼的劍，表示你已經與這隻魔獸
訂了契約，今後將會聽從你的命令。
LONG
            );
    set("unit","把");
    set("light",1);
    set("weapon_class",21);
    set("type","shortblade");
    set("min_damage",13);
    set("max_damage",26);
    set("weight",150);
    set("value",({650,"silver"}) );
}

