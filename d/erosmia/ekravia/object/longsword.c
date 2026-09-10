#include "../ekravia.h"

inherit WEAPON;

void create()
{
        set_name( "longsword", "長劍" );
        add( "id",({ "sword", "longsword" }) );
        set_short( "長劍" );
        set_long( @CLONG
一把普通的長劍, 幾乎每個地方的鐵匠都會製造的武器。
CLONG
        );
        set( "unit", "把");
        set( "weapon_class", 25 );
        set( "type", "longblade" );
        set( "min_damage", 12 );
        set( "max_damage", 24 );
        set( "nosecond",1);
        set( "weight", 160 );
        set( "value", ({ 600, "silver" }) );
}
