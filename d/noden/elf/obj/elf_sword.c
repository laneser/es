
#include <mudlib.h>
inherit WEAPON;

void create()
{
#include <compress_obj.h>
        set_name("longsword", "長劍");
        add ("id",({ "sword" }) );
        set_short( "長劍" );
        set_long(
            "這是一般的精靈所使用的長劍。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 9 );
        set( "type", "longblade" );
        set( "min_damage", 5);
        set( "max_damage", 8 );
        set( "weight", 70 );
        set( "value", ({ 120, "silver" }) );
}

