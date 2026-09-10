#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "ghost shortsword", "畫魂短劍" );
        add( "id",({ "sword", "shortsword" }) );
        set_short( "畫魂短劍" );
        set_long(@LONG
    一把雕飾古雅的楠木柄短劍，劍長尚不及尺。刀刃是由一種不知名黑褐色礦物
□鑄而成，單邊的刀鋒上嵌著一顆綠色晶石，正不斷的透射出詭異的光芒。
LONG);
        set( "unit", "把");
        set( "weapon_class", 42 );
        set( "type", "shortblade" );
        set( "min_damage", 25 );
        set( "max_damage", 37 );
//        set( "bleeding", 10 );
        set( "weight", 50 );
        set( "value", ({ 2175, "gold" }) );
}

