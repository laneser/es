
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "long blade", "長刀" );
        add( "id",({ "sword","blade" }) );
        set_short( "long blade", "長刀" );
        set_long(@AAA
這是一把剛剛升為武士階級的低級武士用劍
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 15 );
        set( "type", "longblade" );
//        set( "bleeding", 4 );
        set( "min_damage", 10 );
        set( "max_damage", 18 );
        set( "weight", 120 );
        set( "value", ({ 420, "silver" }) );
}
