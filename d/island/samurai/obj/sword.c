
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Ninja blade", "忍刀" );
        add( "id",({ "blade","sword" }) );
        set_short( "Ninja blade", "忍刀" );
        set_long(
            " 這是一把鋒利的長劍，是武士團的制式武器\n"
        );
        set( "unit", "把");
        set( "weapon_class", 22 );
        set( "type", "dagger" );
        set( "min_damage", 10 );
        set( "max_damage", 20 );
        set( "weight", 120 );
        set( "value", ({ 320, "silver" }) );
}



