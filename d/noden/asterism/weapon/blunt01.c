
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("stone long hammer", "石制長槌");
        add ("id",({ "hammer" }) );
        set_short("石制長槌");
        set_long(
            "這是一把石制長槌,它能攻擊遠方的敵人。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 23 );
        set( "type", "blunt" );
        set( "min_damage", 15);
        set( "max_damage", 26);
        set( "weight", 240 );
        set( "value", ({ 770, "silver" }) );
}

