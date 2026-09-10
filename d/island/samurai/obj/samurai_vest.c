#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "samurai_vest", "武士戰甲");
        add( "id", ({ "samurai_vest","vest" }) );
        set_short("samurai_vest", "武士戰甲");
        set_long(@AAA
這是一件以重金屬製成之戰甲,能提供不錯的防護,由於造價較
高,所以不是普通武士可以穿的
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 15 );
        set( "defense_bonus", 5 );
        set("material","heavy_metal");
        set( "weight", 250 );
        set( "value", ({ 900, "silver" }) );
}
