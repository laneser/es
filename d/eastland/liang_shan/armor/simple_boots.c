#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("general boots", "麻鞋");
        add( "id", ({ "boots" }) );
        set_short("general boots", "麻鞋");
        set_long(
                "a pair of normal boots .\n",
                "這是一雙非常平凡的麻鞋，劉備以前就賣這個東西長大．\n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material", "cloth");
        set( "armor_class", 3 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "none":1, "acid":1 ]) );
        set( "weight", 70 );
        set( "value", ({ 127, "silver" }) );
}
