#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("sun pill","六陽正氣丹");
        add( "id" , ({ "sun pill"}) );
        set_short( "六陽正氣丹");
        set_long(@C_LONG
這是一顆赤紅色的藥丸,摸起來溫溫。
C_LONG  );      
        set("unit","顆");
        set("weight",1);
        set("no_sale",1);
}
