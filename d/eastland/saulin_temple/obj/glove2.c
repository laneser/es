#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name("liu-li bracers", "琉璃手鐲");
        add( "id", ({"bracers","bracer" }) );
        set_short("琉璃手鐲");
        set_long(@C_LONG
一雙由七彩琉璃石做成的手鐲, 可以在戰鬥中散發出耀眼炫目的光芒
相傳這是王母娘娘座下女神穿帶的手鐲。
C_LONG
       	);
        set( "unit", "對");
        set( "type", "hands" );
        set( "armor_class", 5 );
        set("material","stone");
        set( "defense_bonus", 3 );
        set( "weight", 50 );
        set( "value", ({ 1800, "silver" }) );
}
