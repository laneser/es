
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "cross lance","十字槍" );
        add( "id",({ "lance","cross" }) );
        set_short( "cross lance","十字槍" );
        set_long(@AAA
這是一把巨大的十字槍,除非是個相當有力量的人,不然是用不起這種大兵器的
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 36 );
        set( "type", "thrusting" );
        set( "min_damage", 15 );
        set( "max_damage", 38 );
        set( "weight", 250 );
        set( "value", ({ 1230, "silver" }) );
}



