#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("dog blunt","打狗棒");
        add( "id" , ({ "dog blunt" }) );
        set_short( "打狗棒");
        set_long(@C_LONG
這是一根緣油油的打狗棒,象徵幫主的地位。
C_LONG  );      
        set("unit","根");
        set("weight",1);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
