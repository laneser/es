
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "steel axe", "鋼斧" );
        add( "id",({ "axe" }) );
        set_short( "steel axe", "鋼斧" );
        set_long(@AAA
這是一把鋒利的大斧，使武士團邊境守衛隊愛用的武器
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 25 );
        set( "type", "axe" );
        set( "min_damage", 15 );
        set( "max_damage", 30 );
        set( "weight", 170 );
        set( "value", ({ 620, "silver" }) );
}



