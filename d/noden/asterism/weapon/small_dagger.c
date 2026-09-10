
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("small dagger","小匕首");
        add ("id",({ "dagger" }) );
        set_short( "小匕首");
        set_long(
            "這是一把沒什麼殺傷力的鈍匕首。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 5 );
        set( "type", "dagger" );
        set( "min_damage", 3);
        set( "max_damage", 7 );
        set( "weight", 50 );
        set( "value", ({ 50, "silver" }) );
}

