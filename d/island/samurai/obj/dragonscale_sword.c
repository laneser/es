#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "dragonscale sword","龍鱗之劍" );
        add( "id",({ "dragonscale","sword" }) );
        set_short( "dragonscale sword","龍鱗之劍" );
        set_long(@AAA
這是一把用龍的鱗片打造的長劍，隱含者無比的威力
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 27 );
//        set( "bleeding",17 );
        set( "type", "longblade" );
        set( "min_damage", 12 );
        set( "max_damage", 28 );
        set( "weight", 150 );
        set( "value", ({ 930, "silver" }) );
}