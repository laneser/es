// OpiumPoppy.c		罌粟
//
//			Lilia

#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("Opium poppy", "罌粟");
    add("id", ({"opium", "poppy"}));
    set_short("罌粟");
    set_long("這朵花就是傳說中的罌粟花，是提煉毒品的原料。\n");
    set("ident", "OPIUM");
    set("unit", "朵");
    set("weight", 4);
    set("no_sale", 1);
}

