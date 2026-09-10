#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "a_shu_la_chainmail", "阿修羅之鎧");
        add( "id", ({ "chainmail" }) );
        set_short("a_shu_la_chainmail", "阿修羅之鎧");
        set_long(@AAA
這是武士隊長約修家傳的鎧甲 ，其上刻有一個阿修羅神的圖案
可以讓人感到一股濃濃的殺氣
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 34 );
        set( "defense_bonus", 4 );
        set("material","heavy_metal");
        set( "weight", 250 );
        set( "value", ({ 1200, "silver" }) );
}
