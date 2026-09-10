
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Ninja sword", "忍者刀" );
        add( "id",({ "sword" }) );
        set_short( "Ninja sword", "忍者刀" );
        set_long(@AAA
忍者專用的武器，雖說名稱是刀但卻比平常的刀要短了許多，
或許是忍者為了方便移動而改的吧
AAA
        );
        set( "unit", "把");
//        set( "bleeding",13);
        set( "weapon_class", 25 );
        set( "type", "dagger" );
        set( "min_damage", 10 );
        set( "max_damage", 25 );
        set( "weight", 120 );
        set( "value", ({ 720, "silver" }) );
}



