
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "bird sword", "名刀千鳥" );
        add( "id",({ "bird","sword" }) );
        set_short( "bird sword", "名刀千鳥" );
        set_long(@AAA
這是一把有名的古刀千鳥，在劍身上刻有一個飛鳥的圖案
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 26 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 26 );
        set( "weight", 170 );
        set( "value", ({ 1320, "silver" }) );
}



