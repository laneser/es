
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("Brass huge hammer", "黃銅巨槌");
        add ("id",({ "hammer" }) );
        set_short("黃銅巨槌");
        set_long(
            "這是一把黃銅巨槌。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 20 );
        set( "type", "blunt" );
        set( "nosecond",1);
        set( "min_damage", 11);
        set( "max_damage", 24);
        set( "weight", 240 );
        set( "value", ({ 790, "silver" }) );
}

