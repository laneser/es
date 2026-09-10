
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Ninja dagger", "忍者匕首" );
        add( "id",({ "dagger" }) );
        set_short( "Ninja dagger", "忍者匕首" );
        set_long(@AAA
忍者專用的匕首，雖然短小但確有極佳的破壞力
AAA
        );
        set( "unit", "把");
//        set( "bleeding",5 );
        set( "weapon_class", 30 );
        set( "type", "dagger" );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "weight", 80 );
        set( "value", ({ 1320, "silver" }) );
}



