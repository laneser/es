#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven armband", "精靈臂環");
        add( "id", ({ "armband" }) );
        set_short( "精靈臂環" );
        set_long(
                "這是精靈長老用獨角獸的獨角所磨製成的臂環，其上有種奇特的保護光芒。 \n"
        );
        set( "unit", "雙");
        set( "type", "arms" );
        set( "material", "wood");
        set( "armor_class", 2 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "mental":7, "evil":-3, "fire":-1, "poison":-2 ]) );
        set( "weight", 30 );
        set( "value", ({ 1800, "silver" }) );
}
