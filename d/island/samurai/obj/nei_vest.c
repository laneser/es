#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Thunder Vest", "雷電戰甲");
        add( "id", ({ "thunder","vest" }) );
        set_short("Thunder Vest", "雷電戰甲");
        set_long(@AAA
這是一件附有雷電精靈力量的鎧甲，是妮作戰時所穿的防具，鎧甲
前面還刻有一個風精靈法印！　
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 37 );
        set( "defense_bonus", 6 );
        set("material","element");
        set("special_defense",(["eletric":10]));
        set( "weight", 110 );
        set( "value", ({ 1700, "silver" }) );
}
