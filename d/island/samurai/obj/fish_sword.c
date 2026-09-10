
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "fish sword", "名刀魚承" );
        add( "id",({ "fish","sword" }) );
        set_short( "fish sword", "名刀魚承" );
        set_long(@ANGEL
這是一把有名的古刀魚承,劍身上還刻有一隻魚的圖案
ANGEL
        );
        set( "unit", "把");
        set( "weapon_class", 26 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 26 );
        set( "weight", 170 );
        set( "value", ({ 1120, "silver" }) );
}
