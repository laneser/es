#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name( "elven shield", "精靈盾");
        add( "id", ({ "shield" }) );
        set_short( "精靈盾" );
        set_long(
                "這是精靈王用特殊的金屬所製成的盾，盾上有著精靈的 \n"
                "的標幟。\n"
        );
        set( "unit", "面"); 
        set( "type", "shield" );
        set( "material", "light_metal");
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "mental":4, "evil":-3 ]) );
        set( "extra_skill",([ "block":5 ]) );              
        set( "weight", 50 );
        set( "value", ({ 105, "gold" }) );
        set( "no_sale", 1);
}
