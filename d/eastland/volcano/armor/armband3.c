#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("water armband", "水臂環");
        add( "id", ({ "armband" }) );
        set_short( "水臂環");
        set_long(
                "這個臂環乃是龍王用魔力將水之精煉制而成。\n"
        );
        set("unit","個");
        set( "type", "arms" );
        set( "material", "element");
        set( "armor_class", 2 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "cold":-5, "fire":10 ]) );
        set( "weight", 100 );
        set( "value", ({ 100, "gold" }) );
}






