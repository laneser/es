#include <mudlib.h>

inherit POTION;

void create()
{
        potion::create();
        set_name( "wine","術酒");
        add( "id", ({ "wine" }) );
        set_short( "術酒");
        set_long(
@C_LONG
這是一罐由老村長所調製的術酒，聞起來有股濃郁的藥味，可能
對於身體有病痛的人，具有不少的療效吧。
C_LONG
        );
// so high ???
// set_healing(250);
   set_healing(100);
        set( "no_sale", 1 );
        set( "unit", "罐");
        set( "weight", 40 );
        set( "value", ({ 700, "silver" }) );
        set( "medication",10 );
        set( "effect_critical",10 );
}
