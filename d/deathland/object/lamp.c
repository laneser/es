// Echo/item/lamp.c
#include "../echobomber.h"
inherit OBJECT;
void create()
{
set_name("Lamp","油燈");
set("c_short","一盞油燈");
set("c_long",@Lamp
一盞油燈,似乎有股神奇的力量
Lamp
);
set("id",({"lamp"}));
set( "unit", "盞");
set("weight", 1);
 set("value", ({ 5, "silver" }));
}
void init()
{
add_action("light_lamp","light");
}

int light_lamp(string str)
{
    if (!str||str!="lamp") return 0;
    
}
