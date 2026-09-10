#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Cloak", "冰雪披風");
        add( "id", ({ "snow","cloak" }) );
        set_short("Snow Cloak", "冰雪披風");
        set_long(@AAA
這是一件雪白色的披風，是用高級絲綢加上特殊材料混合織成的，能提供相
當高的防護力
AAA
        );
        set( "unit", "件"); 
        set( "type", "cloak" );
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set("material","cloth");
        set("special_defense",(["cold":-5,"fire":5]));
        set( "weight", 30 );
        set( "no_sale",1);
        set( "value", ({ 1200, "silver" }) );
}
