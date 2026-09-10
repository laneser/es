#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Ninja Vest", "忍者網甲");
        add( "id", ({ "ninja","vest"}) );
        set_short("Ninja Vest", "忍者網甲");
        set_long(@AAA
一件忍者們特有的防護衣，是將細的金屬編織成網狀，既保有
金屬型鎧甲的防護力，又有輕的重量，是少數忍者才能有的防
護衣
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 30 );
        set( "defense_bonus", 3 );
        set("material","element");
        set( "weight", 100 );
        set( "value", ({ 1160, "silver" }) );
}
