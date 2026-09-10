#include "../forest.h"

inherit WEAPON;

void create()
{
        set_name( "sharp blade", "大刀" );
        add( "id",({ "blade", "sharp blade" }) );
        set_short( "鋒利的大刀" );
        set_long( @CLONG
這是一把相當鋒利的大刀, 白晃晃的銳利刀鋒, 令人感受到一種一出
鞘就想見血的霸氣。
CLONG
        );
        set( "unit", "把");
        set( "weapon_class", 18 );
        set( "type", "longblade" );
        set( "min_damage", 8 );
        set( "max_damage", 18 );
        set( "nosecond",1);
        set( "weight", 141 );
        set( "value", ({ 350, "silver" }) );
}
