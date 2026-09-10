#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Dark Cap","黯雲冠");
    add("id",({"hat","cap"}) );
    set_short("黯雲冠");
    set_long(@LONG
這是件黯淡無光的帽子，可怕的顏色彷佛是要將人吞噬一般。
LONG
            );
    set("unit","件");
    set("type","head");
    set("material","wood");
    set("armor_class",6);
    set("defense_bonus",1);
    set("weight",100);
    set("value",({550,"silver"}) );
}
