
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "occult shortsword", "神秘短劍" );
        add( "id",({ "sword", "shortsword" }) );
        set_short( "神秘短劍" );
        set_long(
            "這是巴德北特.龐博所使用的短劍。\n"
        );
        set( "unit", "把");
        set( "weapon_class", 40 );
        set( "type", "shortblade" );
        set( "min_damage", 25 );
        set( "max_damage", 35 );
        set( "weight", 180 );
        set( "value", ({ 300, "gold" }) );
}

