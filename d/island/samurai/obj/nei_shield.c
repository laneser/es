#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Thunder Shield", "雷電神盾");
        add( "id", ({ "thunder","shield" }) );
        set_short("Thunder Shield", "雷電神盾");
        set_long(@AAA
這是一件附有雷電精靈力量的盾牌
AAA
        );
        set( "unit", "件"); 
        set( "type", "shield" );
        set( "armor_class", 8 );
        set( "defense_bonus", 6 );
        set("material","element");
        set("special_defense",(["eletric":6]));
        set( "weight", 100 );
        set( "value", ({ 1200, "silver" }) );
}
