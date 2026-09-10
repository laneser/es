#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("yellow boots", "黃皮襯底靴");
        add( "id", ({ "boots" }) );
        set_short("yellow boots", "黃皮襯底靴");
        set_long(
                "This is a pair of boots made of fur of cow .\n",
                "這是由上好小牛皮精製的皮鞋，鞋底有個鱷魚標誌．\n"
        );
        set( "unit", "雙");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 50 );
        set( "value", ({ 680, "silver" }) );
}
