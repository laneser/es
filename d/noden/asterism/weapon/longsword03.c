
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Silver longsword", "銀劍");
        add ("id",({ "sword" }) );
        set_short("銀劍");
        set_long(
            "這是銀製的劍，自古傳言銀製品天生帶有神聖的力量。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 27 );
        set( "type", "longblade" );
        set( "min_damage", 20);
        set( "max_damage", 29 );
        set( "weight", 160 );
        set( "value", ({ 2500, "silver" }) );
}

