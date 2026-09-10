#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Clothes", "冰雪護袍");
        add( "id", ({ "snow","clothes" }) );
        set_short("Snow Clothes", "冰雪護袍");
        set_long(@AAA
這是一件雪白色的長袍，是用高級絲綢加上特殊材料混合織成的，能提供相
當高的防護力，而在袍子的邊角還繡有紅色的帶子！！
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 34 );
        set( "defense_bonus", 6 );
        set("material","cloth");
        set("special_defense",(["cold":-15,"fire":15]));
        set( "weight", 90 );
        set( "no_sale",1);
        set( "value", ({ 1600, "silver" }) );
}
