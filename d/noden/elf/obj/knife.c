
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "elven knife", "精靈小刀");
        add ("id",({ "knife"}) );
        set_short( "精靈小刀" );
        set("unit", "把");
        set_long(
            "這是幼小的精靈們用石頭做成的玩具小刀。\n"
        );
        set( "weapon_class", 4 );
        set( "type", "dagger" );                        
        set( "min_damage", 2 );
        set( "max_damage", 5 );
        set( "weight", 35 );
        set( "value", ({ 8, "silver" }) );
}
