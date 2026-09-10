#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Snow Gloves", "冰雪手套");
        add( "id", ({ "snow","gloves" }) );
        set_short("Snow Gloves", "冰雪手套");
        set_long(@AAA
這是一件雪白色的手套，是用高級絲綢加上特殊材料混合織成的，能提供相
當高的防護力！！
AAA
        );
        set( "unit", "件"); 
        set( "type", "hands" );
        set( "armor_class", 4 );
        set( "defense_bonus", 3 );
        set("material","cloth");
        set("special_defense",(["cold":-5,"fire":5]));
        set( "weight", 30 );
        set( "no_sale",1);
        set( "value", ({ 980, "silver" }) );
}
