
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Chilin teeth", "麒麟牙" );
        add( "id",({ "teeth", "shortsword" }) );
        set_short( "麒麟牙" );
        set_long("這是麒麟經過數千年時光演化出的超級武器\n");
        set( "unit", "把");
        set( "weapon_class", 44 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 33 );
        set( "weight", 180 );
        set( "value", ({ 400, "gold" }) );
}

