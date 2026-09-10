
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("shell armband", "龜甲臂環");
        add( "id", ({"armband" }) );
        set_short("龜甲臂環");
        set_long(
                "這是一個用烏龜甲殼做成的臂環，花花綠綠的滿好看的。\n"
        );
        set( "unit", "個");
        set( "type", "arms" );
        set( "material", "stone" );
        set( "defense_bonus", 1 );
        set( "weight", 30 );
        set( "value", ({ 670, "silver" }) );
}
