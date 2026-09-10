#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("silver armband", "銀臂環");
        add( "id", ({"armband" }) );
        set_short("a silver armband", "銀臂環");
        set_long(
                "An armband used by last dwarven guard.\n",
                "一個銀臂環,有相當好的防護力\n"
        );
        set( "unit", "個");
        set( "type", "arms" );
        set( "material", "heavy_metal");
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "weight", 40);
        set( "value", ({ 770, "silver" }) );
}
