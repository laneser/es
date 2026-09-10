#include "../tsunami.h"

inherit OBJECT;

void create()
{
    set_name("Spirit Ball","聖騎士元神");
    add("id",({"ball","spirit"}) );
    set_short("聖騎士元神");
    set_long(@LONG
這是聖騎士的元神，乍看之下，只是一顆小小的，亮亮的光球。
如果你能將它送回聖騎士的金身中，將會有不可思議的事情發生
哦！
LONG
            );
    set("unit","顆");
    set("weight",50);
    set("value",({1,"copper"}) );
    set("no_sale",1);
    set("ball",1);
 }
