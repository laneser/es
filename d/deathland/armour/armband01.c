#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("dwarven armband", "矮人臂環");
        add( "id", ({"armband" }) );
        set_short("a dwarven armband", "矮人臂環");
        set_long(
                "An armband used by dwarf.\n",
                "一個矮人專用的臂環\n"
        );
        set( "unit", "個");
        set( "type", "arms" );
        set( "material", "light_metal" );
        set( "armor_class", 2 );
        set( "defense_bonus", 1 );
        set( "weight", 30 );
        set( "value", ({ 720, "silver" }) );
}
