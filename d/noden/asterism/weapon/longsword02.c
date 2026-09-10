
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Brone longsword", "青銅長劍");
        add ("id",({ "sword" }) );
        set_short("青銅長劍");
        set_long(
            "這是青銅製的鋒利長劍。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 23 );
        set( "type", "longblade" );
        set( "min_damage", 17);
        set( "max_damage", 25 );
        set( "weight", 190 );
        set( "value", ({ 1720, "silver" }) );
}

