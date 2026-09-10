#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("crown","皇冠");
        add( "id", ({ "helmet" }) );
        set_short( set_color("皇冠","HIY"));
        set_long(@C_LONG
一頂純金打造的金黃色皇冠，上面鑲有珍珠瑪瑙，閃爍著珠光寶氣。
C_LONG
        );
        set( "unit","頂");
        set( "type", "head" );
        set( "material","heavy_metal");
        set( "armor_class",7 );
        set( "defense_bonus",1);
        set( "weight", 100 );
        set( "value", ({ 3500, "silver" }) );
}



