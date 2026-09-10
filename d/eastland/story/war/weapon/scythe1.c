#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "blood scythe", "血鐮刀" );
    add( "id", ({ "scythe" }) );
    set_short( "血鐮刀" );
    set_long(@LONG
一把沾滿血跡的鐮刀，刀身呈現赤紅色。
LONG
    );
    set( "unit", "把" );
    set( "weight", 40 );
    set( "value", ({ 800, "silver" }) );
    setup_weapon("longblade", 20,14,22);
}
