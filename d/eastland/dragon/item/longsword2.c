
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult longsword", "神秘長劍" );
        add( "id",({ "sword", "longsword" }) );
        set_short( "神秘長劍" );
        set_long(
            "這是把神秘長劍。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 19 );
        set( "type", "longblade" );
        set( "min_damage", 10 );
        set( "max_damage", 20 );
        set( "weight", 150 );
        set( "value", ({ 150, "gold" }) );
}

