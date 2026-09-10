#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("spirit ball","巽靈珠");
        add( "id" , ({ "ball" }) );
        set_short( "巽靈珠");
        set_long(@C_LONG
一顆墨黑色的圓球，猶如一粒黑珍珠。
C_LONG  );      
        set("unit","顆");
        set("weight",50);
        set("no_sale",1);
        set("spiritball",1);
        set("master","???");
        set("value", ({1, "silver"}) );
}
