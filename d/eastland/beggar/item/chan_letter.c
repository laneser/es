#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("chan letter","家書");
        add( "id" , ({ "chan letter" }) );
        set_short( "家書");
        set_long(@C_LONG
這是一封黃色的家書。
C_LONG  );      
        set("unit","封");
        set("weight",5);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
