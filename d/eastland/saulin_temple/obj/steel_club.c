#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "steel club", "渾鐵棒");
        add ("id",({ "club"}) );
        set_short("渾鐵棒");
        set("unit", "把");
        set_long(@C_LONG
這是一把由渾鐵所鑄造的棒子，看起來不輕的樣子。
C_LONG
        );
        set( "weapon_class", 16);
        set( "type", "bo");                        
        set( "min_damage", 10);
        set( "max_damage", 18);
        set( "weight", 160);
        set( "value", ({ 380, "silver" }) );
}
