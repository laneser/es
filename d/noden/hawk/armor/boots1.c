#include <mudlib.h>

inherit ARMOR;

void create()
{
set_name( "White Boots","凌雲蔽日靴" );
        add( "id", ({ "boots","white boots" }) );
	set_short( "凌雲蔽日靴" );
        set_long(
                "一雙紫色的靴子，上面繪有白色的火焰與一朵朵的白雲。\n"
        );
        set( "unit", "雙" );
        set("material","wood");
        set( "type", "feet" );
        set( "armor_class", 7 );
        set( "defense_bonus", 3 );
        set( "weight", 35 );
        set( "value", ({ 1410, "silver" }) );
}
