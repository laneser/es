#include "../tsunami.h"

inherit OBJECT;

void create()
{
    set_name("Radish","蘿蔔");
    set_short("蘿蔔");
    set_long(@LONG
這只是一般的紅色圓形小蘿蔔!
LONG
            );
    set("unit","只");
    set("weight",50);
    set("value",({0,"silver"}) );
    set("give_me_radish",1);
 }

