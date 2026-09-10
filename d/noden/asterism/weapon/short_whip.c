
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Short whip","短鞭");
        add ("id",({ "whip" }) );
        set_short("短鞭");
        set_long(
            "這是一條馴獸師用的短鞭，因為它是五條鞭子纏在同一個握把，\n"
            "所以打起來特別痛。"
        );
        set( "unit", "條");
        set( "weapon_class", 25 );
        set( "type", "whip" );
        set( "min_damage", 18);
        set( "max_damage", 25 );
        set( "weight", 80 );
        set( "value", ({ 840, "silver" }) );
}

