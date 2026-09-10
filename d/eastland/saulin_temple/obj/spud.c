#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "spud", "小鋤頭");
        add ("id",({ "spud"}) );
        set_short("小鋤頭");
        set("unit", "把");
        set_long(
            "這是一把用來整地的小鋤頭。\n"
        );
        set( "weapon_class", 6 );
        set( "type", "blunt" );                        
        set( "min_damage", 5);
        set( "max_damage", 10);
        set( "weight", 65 );
        set( "value", ({ 80, "silver" }) );
}
