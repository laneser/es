#include "../tsunami.h"

inherit OBJECT;

void create()
{
    set_name("Seed of Luoko","龍皇的種子");
    add("id",({"seed"}) );
    set_short("種子");
    set_long(@LONG
這是龍皇的種子，一副圓滾滾，亮晶晶的模樣，真沒想到這竟會是守護靈！
還是趕快想辦法將它種到御花園去吧，免得乾掉了！
LONG
             );
    set("unit","顆");
    set("weight",5);
    set("value",({5,"copper"}) );
    set("no_sale",1);
    set("luoko_seed",1);
}

    