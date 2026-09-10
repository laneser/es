
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "dragonlight sword","名刀龍光");
        add( "id",({ "dragonlight","sword" }) );
        set_short( "dragonlight sword","名刀龍光" );
        set_long(@AAA
這是一把有名的寶刀″龍光″，是武士團中的佼佼者約克的武器
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 30 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 32 );
        set( "weight", 170 );
        set( "value", ({ 1030, "silver" }) );
}



