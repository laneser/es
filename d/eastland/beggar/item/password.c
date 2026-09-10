#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("password","手諭");
        add( "id" , ({ "password" }) );
        set_short( "手諭");
        set_long(@C_LONG
這是丐幫幫主的手諭。
C_LONG  );      
        set("unit","件");
        set("weight",5);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
