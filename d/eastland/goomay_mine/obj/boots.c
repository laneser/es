#include "../zeus.h"

inherit ARMOR;

void create()
{
        set_name("comfortable boots", "快意薄靴");
        add( "id", ({ "boots","boot" }) );
        set_short("快意薄靴");
        set_long(@AA
這是一雙由軟皮革所製成的薄底快靴，穿起來又軟又舒服，鞋類中的上品．
AA
);
        set( "unit", "雙");
        set( "type", "feet" );
        set("material","leather");
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "weight", 40 );
        set( "value", ({ 600, "silver" }) );
        }