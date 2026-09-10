#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Pracrice pants","武道褲裙");
    add("id",({"skirt","pants"}) );
    set_short("武道褲裙");
    set_long(@LONG
這是一般的武道褲裙，乃一般習武之士習武時必著之裝備！
LONG
            );
    set("unit","件");
    set("type","legs");
    set("material","cloth");
    set("armor_class",2);
    set("defense_bonus",0);
    set("weight",50);
    set("value",({20,"silver"}) );
}
    