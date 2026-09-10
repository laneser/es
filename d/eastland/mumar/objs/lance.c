#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("lance", "長槍");
        add ("id",({ "lance" }) );
        set_short("長槍");
        set_long(
            "一把長槍，槍頭長閃著銀光。\n"
        );
        set( "unit", "把" );
        set( "weapon_class", 13 );
        set( "type", "thrusting" );
        set( "min_damage", 6 );
        set( "max_damage", 14 );
        set( "weight", 150 );
        set( "value", ({ 200, "silver" }) );
}
