#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("jade shield", "翡翠盾牌");
        add( "id", ({ "shield" }) );
        set_short("翡翠盾牌");
        set_long(
                "這是一面鑲滿翡翠的盾牌\n"
        );
        set("unit","塊");
        set( "type", "shield" );
        set( "material", "element" );
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "special_defense", ([ "electric":3 ]) );
        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}