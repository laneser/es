#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Jupiter armband","丘比特烏金臂環" );
        add( "id", ({ "armband","jupiter armband" }) );
        set_short( "丘比特烏金臂環" );
        set_long(
                "這是丘比特所制的奇妙臂環, 烏金更是極其罕有的材料。\n"
        );
        set( "unit", "只" );
        set("material","thief");
        set( "type", "arms" );
        set( "armor_class", 1 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 4700, "silver" }) );
}
