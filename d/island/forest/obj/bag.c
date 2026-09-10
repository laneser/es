#include <mudlib.h>

inherit CONTAINER;

void create()
{
    ::create();
    set_name("Small Bag","歷險小揹包");
    add("id",({ "bag" }) );
    set_short("歷險小揹包");
    set_c_open_long("這是一般冒險家愛用的小揹包，可用來裝不少東西哦！\n");
    set("weight",10);
    set("weight_apply",60);
    set("max_load",200  );
    set("value",({100,"silver"}) );
    set("prevent_insert",1);
    set("prevent_put_money",1);
}
    