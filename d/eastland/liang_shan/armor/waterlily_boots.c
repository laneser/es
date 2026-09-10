#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("waterlily boots", "藕絲步雲履");
        add( "id", ({ "boots" }) );
        set_short("藕絲步雲履");
        set_long(
                "這是由蓮藕的纖維所製成的鞋子，質輕而且十分耐用．\n"
        );
        set( "no_sale",1);
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material", "element");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "evil":8, "divine":-8,"poison":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 2740, "silver" }) );
}
