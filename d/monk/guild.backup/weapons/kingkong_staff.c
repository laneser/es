#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "king-kong staff", "金剛杖");
        add ("id",({ "staff"}) );
        set_short( "king-kong staff", "金剛杖");
        set("unit", "把");
        set_long(
            "",@C_LONG
這把金剛杖外表黝黑沒有光澤，還發出一股逼人的寒氣，看起來十分沈重，
據說是由千年玄鐵鑄造而成。
C_LONG
        );
        set( "weapon_class", 35);
        set( "type", "blunt");
        set( "min_damage", 25);
        set( "max_damage", 43);
        set( "no_sale", 1);
        set( "weight",180 );
        set( "value", ({ 180, "silver" }) );
}
