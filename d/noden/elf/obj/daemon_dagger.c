
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "demonic dagger", "惡魔匕首" );
        add( "id",({ "dagger"}) );
        set_short( "惡魔匕首" );
        set_long(
            "這是惡魔小偷的專用武器。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 17 );
        set( "type", "dagger" );
        set( "min_damage", 8 );
        set( "max_damage", 17 );
        set( "second",1);
        set( "weight", 100 );
        set( "value", ({ 1200, "silver" }) );
}

