#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_chainmail", "武士鎧甲");
        add( "id", ({ "chainmail" }) );
        set_short("samurai_chainmail", "武士鎧甲");
        set_long(@AAA
一個低等級武士所穿的鎧甲，應為這是低等級武士的裝備 
所以也不能提供什麼好防護力
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 15 );
        set( "defense_bonus", 3 );
        set("material","heavy_metal");
        set( "weight", 200 );
        set( "value", ({ 450, "silver"}) );
}
