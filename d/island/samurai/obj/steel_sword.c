
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "steel sword", "精鋼長劍" );
        add( "id",({ "sword" }) );
        set_short( "steel sword", "精鋼長劍" );
        set_long(@AAA
這是以把鋒利的長劍，是用特殊鋼材做成的，是武士團邊境守備隊的制式武器
AAA
);
        set( "unit", "把");
        set( "weapon_class", 30 );
//        set( "bleeding", 5 );
        set( "type", "longblade" );
        set( "min_damage", 10 );
        set( "max_damage", 28 );
        set( "weight", 170 );
        set( "value", ({ 720, "silver" }) );
}



