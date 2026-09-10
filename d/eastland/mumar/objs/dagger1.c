#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name( "stpuid dagger", "鈍匕首" );
        add( "id", ({ "dagger" }) );
        set_short( "鈍匕首" );
        set_long(
                "一把短而鈍的匕首，刀刃上都是缺口。\n"
        );
        set( "unit", "把" );
        set( "type", "dagger" );
        set( "weapon_class", 10 );
        set( "min_damage", 4 );
        set( "max_damage", 13 );
        set( "weight", 30 );
        set( "value", ({ 120, "silver" }) );
}
