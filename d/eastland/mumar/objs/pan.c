#include <mudlib.h>
 
inherit WEAPON;
 
void create()
{
        set_name("pan", "平底鍋");
        set_short("平底鍋");
        set_long(
                "這是一支廚師用的平底鍋。\n"
        );
        set( "unit", "支" );
        set( "weight", 80 );
        set( "type", "blunt" );
        set( "weapon_class",10 );
        set( "min_damage", 6 );
        set( "max_damage", 12 );
        set( "value", ({ 50, "silver" }) );
}
