
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("long whip","長鞭");
        add ("id",({ "whip" }) );
        set_short("長鞭");
        set_long(
            "這是一條很長的鞭子。仔細一看, 上面什麼花紋都沒有。\n"
        );
        set( "unit", "條");
        set( "weapon_class", 20 );
        set( "type", "whip" );
        set( "min_damage", 17);
        set( "max_damage", 19 );
        set( "weight", 110 );
        set( "value", ({ 840, "silver" }) );
}

