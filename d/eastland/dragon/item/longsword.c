
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
        set( "weapon_class", 42 );
        set( "type", "longblade" );
        set( "min_damage", 25 );
        set( "max_damage", 45 );
        set( "weight", 220 );
        set( "value", ({ 600, "gold" }) );
}

